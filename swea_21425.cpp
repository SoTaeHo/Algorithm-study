#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int a;
        int b;
        int n;
        int cnt = 0;

        cin >> a >> b >> n;

        while(true) {

            if (a < b) {
                a += b;
            } else {
                b += a;
            }
            cnt++;
            if (a > n || b > n)
                break;
        }
        cout << cnt << '\n';
    }
}