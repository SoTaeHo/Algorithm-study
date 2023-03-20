#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    string result = "";
    cin >> n;
    int * arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    // sort
    sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        result.append(to_string(arr[i])).append("\n");
    }

    cout << result;

    delete[] arr;

    return 0;
}