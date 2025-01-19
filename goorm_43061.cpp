#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;

    cin >> n;

    vector<int> max(n, 0);
    vector<int> calc(n , 0);

    for(int i = n - 1; i >= 0; i--) {
        cin >> max[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        cin >> calc[i];
    }

    cin >> k;

    for(int i = 0; i < k; k++) {
        calc[0]++;
        for(int j = 0; j < n; j++) {
            if(calc[j] == max[j]) {
                calc[j] = 0;
                if(j + 1 != n) {
                    calc[j + 1] += 1;
                }
            }
        }
        for(int j = 0; j < n; j++) {
            cout << calc[j];
        }
    }

    for(int i = 0; i < n; i++) {
        cout << calc[i];
    }

}