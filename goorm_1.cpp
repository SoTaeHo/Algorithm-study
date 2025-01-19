#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int m;

    cin >> n >> m;

    vector<int>height(n, 0);
    vector<bool>rain(n, false);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    for(int i = 0; i < m; i++) {
        int s;
        int e;
        cin >> s >> e;
        for(int j = s; j <= e; j++) {
            height[j - 1]++;
            rain[j - 1] = true;
        }
        if ((i + 1) % 3 == 0) {
            for(int j = 0; j < n; j++) {
                if(rain[j]) {
                    height[j]--;
                    rain[j]=false;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << height[i] << " ";
    }
    // -1 0 1 0 2
    // 0 0 1 0 2       1
    // 0 1 1 0 2      2
    // 0 1 2 0 2      3
    // -1 0 1 0 2     배수 작동
    // -1 0 1 1 3     4
    // -1 0 1 2 4     5
    //
}