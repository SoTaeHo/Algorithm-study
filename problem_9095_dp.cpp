#include "iostream"
#include "vector"

using namespace std;

int t, n;

vector<int> dp(10, 0);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    dp[0] = 1; // 1
    dp[1] = 2; // 2, 1 + 1
    dp[2] = 4; // 3, 2 + 1, 1 + 2, 1 + 1 + 1
    for (int i = 3; i < 10; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n - 1] << '\n';
    }
}

