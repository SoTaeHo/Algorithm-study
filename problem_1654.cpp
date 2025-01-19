#include <iostream>
#include <vector>

using namespace std;

int k, n;
int main() {
    cin >> k >> n;
    long long min = 0, max = 0, mid = 1;

    vector<long> arr(k);
    for(int i = 0; i < k; i ++) {
        cin >> arr[i];
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    max++;
    while(min + 1 < max) {
        mid = (min + max) / 2;
//        cout << min << '\n';
//        cout << mid << '\n';
//        cout << max << endl << endl;

        long sum = 0;
        for(int i = 0; i < k; i++) {
            sum += arr[i] / mid;
        }

        if (sum >= n) {
            min = mid;
        }
        else {
            max = mid;
        }

    }
    cout << min;

}