#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int n, result = 0x11111111;
vector<vector<int>> s;

bool elementOf(const vector<int>& arr, int num) {
    for (int i : arr) {
        if (i == num)
            return true;
    }
    return false;
}

void dfs(int num, int r, vector<int>& arr, int cur){

    if (r == 0) {
        int start_sum = 0;
        int link_sum = 0;
        for(auto & i : arr) {
            for(auto & j : arr) {
                if (i == j)
                    continue;
                start_sum += s[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (elementOf(arr, j) || elementOf(arr, i))
                    continue;
                link_sum += s[i][j];
            }
        }
        if(abs(start_sum - link_sum) < result)
            result = abs(start_sum - link_sum);
        return;
    }

    for (int i = cur; i <= num; i++) {
        arr.push_back(i);
        dfs(num, r - 1, arr, i + 1);
        arr.pop_back();
    }
}

int main(){
    cin >> n;

    s.resize(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    vector<int> start;
    dfs(n - 1, n / 2, start, 0);
    cout << result;


}

