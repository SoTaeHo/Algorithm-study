#include "iostream"
#include "vector"
#include "set"

using namespace std;

int main(void) {
    int n, s, temp, sum = 0, start = 0, end = 0;
    vector<int> seq;
    set<int> result;
    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        seq.push_back(temp);
    }

    while(1) {

        cout << "start : " << start << " / end : " << end << " / sum : " << sum << endl;

        if(sum >= s) {
            result.insert(end - start);
            sum -= seq[start++];
        }
        else if (end == n) break;
        else {
            sum += seq[end++];
        }
    }
    cout << *result.begin() << endl;

//    // 부분합, 시간초과
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n - i; j++) {
//            int sum;
//            if (j == 0) {
//                sum = sumVector[i];
//            }
//            else {
//                sum = sumVector[j + i] - sumVector[j - 1];
//            }
//            if(sum >= s) {
//                cout << i + 1;
//                return 0;
//            }
//        }
//    }
//    cout << 0;

//    시간초과 발생
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n-i; j++) {
//            int sum = 0;
//            for(int k = 0; k < i + 1; k++) {
//                sum += seq[j+k];
//            }
//            if(sum >= s) {
//                cout << i+1;
//                return 0;
//            }
//        }
//    }
//    cout << 0;

    return 0;
}