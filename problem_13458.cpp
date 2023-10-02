#include "iostream"
#include "vector"
using namespace std;

int n, b, c;
long long result = 0;
vector<int> a;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> b >> c;

//    time out
//    for (int i = 0; i < n; i++) {
//        int candidate = a[i];
//        candidate -= b;
//        result++;
//        while (candidate > 0) {
//            candidate -= c;
//            result++;
//        }
//    }
    for (int i = 0; i < n; i++) {
        int candidate = a[i];
        candidate -= b;
        result++;
        if (candidate <= 0) {
            continue;
        }
        if (candidate % c == 0) {
            result += candidate / c;
        } else {
            result += (candidate / c) + 1;
        }
    }
    cout << result;
}