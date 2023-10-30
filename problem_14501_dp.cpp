#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int n;
vector<pair<int, int>> schedule;
vector<int> dp;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    dp.resize(n + 1, 0);
    int day, pay, prev;
    for (int i = 0; i < n; i++) {
        cin >> day >> pay;
        schedule.emplace_back(day, pay);
    }

    for(int i = n - 1; i >= 0; i--) {
        prev = i + schedule[i].first;
        if (prev > n) {
            dp[i] = dp[i + 1];
        } else {
            dp[i] = max(dp[i + 1], dp[prev] + schedule[i].second);
        }
    }
    cout << dp[0];
}