//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//
//    for (int i = 0; i < t; i++) {
//        int n;
//        int result = 0;
//
//        cin >> n;
//        vector<double> arr;
//        arr.resize(n);
//        for(int j = 0; j < n; j++) {
//             cin >> arr[j];
//        }
//
//
//        for(int j = 0; j < n; j++) {
//            for(int k = j + 1; k < n; k++) {
//                if (arr[j] * arr[k] - int(arr[j] * arr[k]) < 1e-9) {
//                    result++;
//                }
//            }
//        }
//
//        cout << result << '\n';
//    }
//}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

// 유한소수의 소수 자릿수를 계산하는 함수
int countDecimalPlaces(const string& number) {
    size_t pos = number.find('.');
    if (pos == string::npos) return 0;  // 정수인 경우 소수 자릿수는 0
    return number.length() - pos - 1;
}

// 소수 자릿수별 개수 정보를 기반으로 조합의 개수를 계산하는 함수
long long calculateCombinations(const unordered_map<int, long long>& decimalCount) {
    long long count = 0;

    // 소수 자릿수 0~9에 대해 각각 카운트
    for (int i = 0; i <= 9; i++) {
        if (decimalCount.count(i) == 0) continue;

        long long numCountI = decimalCount.at(i);

        if (i * 2 == 9) {
            // 소수 자릿수 합이 9를 만족하는 같은 자릿수 조합
            count += (numCountI * (numCountI - 1)) / 2;
        } else if (decimalCount.count(9 - i)) {
            // 소수 자릿수 합이 9가 되는 다른 자릿수 조합
            long long numCountJ = decimalCount.at(9 - i);
            count += numCountI * numCountJ;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        unordered_map<int, long long> decimalCount;  // 각 소수 자릿수별 유한소수의 개수를 저장

        // 각 유한소수의 소수 자릿수를 구하여 개수 집계
        for (int i = 0; i < N; i++) {
            string number;
            cin >> number;
            int decimalPlaces = countDecimalPlaces(number);
            decimalCount[decimalPlaces]++;
        }

        // 조합 계산
        long long count = calculateCombinations(decimalCount);
        cout << count << endl;
    }
    return 0;
}
