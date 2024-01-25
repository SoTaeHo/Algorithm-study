#include <iostream>
#include <vector>

using namespace std;

int n, p, s, m, d;
int max_num = -2147483648, min_num = 2147483647;
vector<int> arr;

void rec(int prev, int num, int add, int sub, int mul, int div) {
    if (num == 0) {
        if (prev > max_num) {
            max_num = prev;
        }
        if (prev < min_num) {
            min_num = prev;
        }

        return;
    }
    if (add > 0) {
        rec(prev + arr[n - num], num - 1, add - 1, sub, mul, div);
    }

    if (sub > 0) {
        rec(prev - arr[n - num], num - 1, add, sub - 1, mul, div);
    }

    if (mul > 0) {
        rec(prev * arr[n - num], num - 1, add, sub, mul - 1, div);
    }

    if (div > 0) {
        rec(prev / arr[n - num], num - 1, add, sub, mul, div - 1);
    }

}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cin >> p >> s >> m >> d;
    rec(arr[0],n - 1, p, s, m, d);

    cout << max_num << endl << min_num;
}
