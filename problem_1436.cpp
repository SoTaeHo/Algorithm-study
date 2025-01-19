#include <iostream>

using namespace std;

int main() {
   int n;
   cin >> n;

   int num = 666;
   int result = 1;

   while (result != n) {
//       cout << result << num << endl;
       num++;
       int temp = num;
       int remain;
       int cnt = 0;
       while(temp != 0) {
            remain = temp % 10;
            if (remain == 6) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == 3) {
                result++;
                break;
            }
            temp /= 10;
//            cout << temp;
       }
   }
   cout << num;

}

// 666, 1666, 2666, 3666 4666 5666 6660 ~ 6669 7666 8666 9666 : 0 ~ 9 까지 10개, 6나오면 + 9
// 10666 11666 12666 13666 14666 15666 / 16660 ~ 16669 / 17666 18666 19666 19개
// 15666 다음은 16666이 아닌 16660 ~ 16669 / 17666 18666 19666 20666
// 55666 56660
// 56669 > 57666 58666 59666 60666 61666 62666 63666 64666 65666 66600 +
// 66666 : 19 * 6 = 114 + 67
