#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0 ; i < t ; i++) {
         int n;
         int p;

         cin >> n >> p;

         int cur = 0;
         for(int j = 1; j <= n; j++) {
             cur += j;
             if(cur == p)
                 cur--;
         }
         cout << cur << '\n';
    }
}