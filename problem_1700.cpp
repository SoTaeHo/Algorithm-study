#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void) {
    int n, k, count = 0;
    cin >> n >> k;

    int* arr_k = new int[k];
    set<int> nowUse;
    set<int> temp;
    set<int> diff;

    for(int i = 0; i < k; i++) {
        cin >> arr_k[i];
    }
//    if(n == 1) {
//        for(int i = 1; i < k; i++) {
//            if(arr_k[i-1] != arr_k[i]) {
//                count++;
//            }
//        }
//        cout << count << endl;
//        return 0;
//    }
//    for(int i = 0; i < n; i++) {
//        if(nowUse.find(arr_k[i]) != nowUse.end()) {
//            continue;
//        }
//        nowUse.insert(arr_k[i]);
//    }

    for(int i = 0; i < k; i++) {
        // 이미 멀티탭 배열에 존재하면 continue
        if(nowUse.find(arr_k[i]) != nowUse.end()) {
            continue;
        }
        // 멀티탭에 빈 칸이 있으면 삽입
        else if(nowUse.size() < n) {
            nowUse.insert(arr_k[i]);
            continue;
        }

        // 멀티탭에 존재하지 않으면 가장 오래 사용하지 않을 요소를 찾아서 교체
        for(int j = i + 1; j < k; j++) {
            if(nowUse.size() - 1 == temp.size()) {
                break;
            }
            if(nowUse.find(arr_k[j]) != nowUse.end()) {
                temp.insert(arr_k[j]);
            }
        }

        set_difference(nowUse.begin(), nowUse.end(), temp.begin(), temp.end(), inserter(diff, diff.begin()));
        nowUse.erase(*diff.begin());
        count++;
        nowUse.insert(arr_k[i]);
        diff.clear();
        temp.clear();
    }

    cout << count << endl;

    delete[] arr_k;
    return 0;
}