#include <iostream>
using namespace std;


int main(void) {

    string subject[20];
    float credit[20];
    string score[20];
    float result;
    float cnt;

    for(int i = 0; i < 20; i++) {
        cin >> subject[i] >> credit[i] >> score[i];
    }

    for(int i =0; i < 20; i++) {
       if (score[i] == "A+") {
           result += credit[i] * 4.5;
           cnt += credit[i];
       } else if(score[i] == "A0") {
           result += credit[i] * 4.0;
           cnt += credit[i];
       } else if(score[i] == "B+") {
           result += credit[i] * 3.5;
           cnt += credit[i];

       } else if(score[i] == "B0") {
           result += credit[i] * 3.0;
           cnt += credit[i];

       } else if(score[i] == "C+") {
           result += credit[i] * 2.5;
           cnt += credit[i];

       } else if(score[i] == "C0") {
           result += credit[i] * 2.0;
           cnt += credit[i];

       } else if(score[i] == "D+") {
           result += credit[i] * 1.5;
           cnt += credit[i];

       } else if(score[i] == "D0") {
           result += credit[i] * 1.0;
           cnt += credit[i];

       } else if(score[i] == "F") {
           result += credit[i] * 0.0;
           cnt += credit[i];
       }

    }
    cout << result / cnt << endl;

    return 0;
}