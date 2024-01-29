#include <iostream>
#include <vector>

using namespace std;

int K;
vector<vector<int>> gear;


void rotate(int num, int dir) {
    vector<int> temp;
    // 반시계
    if (dir == -1) {
        for(int i = 1; i < 8; i++) {
            temp.push_back(gear[num][i]);
        }
        temp.push_back(gear[num][0]);
        gear[num] = temp;
    // 시계
    } else if (dir == 1) {
        temp.push_back(gear[num][7]);
        for(int i = 0; i < 7; i++) {
            temp.push_back(gear[num][i]);
        }
        gear[num] = temp;
    }
}

int main(){

    string n;

    for(int i = 0; i < 4; i++) {
        cin >> n;
        gear.emplace_back();
        for (int j = 0; j < 8; j++) {
            gear[i].push_back(n[j] -'0');
        }
    }
//    for(auto & i : gear) {
//        for(auto & j : i) {
//            cout << j;
//        }
//        cout << endl;
//    }

    cin >> K;
    int num, dir;
    for(int i = 0; i < K; i++) {
        cin >> num >> dir;
        num -= 1;

        bool first = gear[0][2] ^ gear[1][6];
        bool second = gear[1][2] ^ gear[2][6];
        bool third = gear[2][2] ^ gear[3][6];

        if (num == 0) {
            rotate(num, dir);
            if (first) {
                rotate(1, -dir);
                if (second) {
                    rotate(2, dir);
                    if (third) {
                        rotate(3, -dir);
                    }
                }
            }
        } else if (num == 1) {
            rotate(num, dir);
            if (first) {
                rotate(0, -dir);
            }
            if (second) {
                rotate(2, -dir);
                if (third) {
                    rotate(3, dir);
                }
            }
        } else if (num == 2) {
            rotate(num, dir);
            if (second) {
                rotate(1, -dir);
                if (first) {
                    rotate(0, dir);
                }
            }
            if (third) {
                rotate(3, -dir);
            }
        } else if (num == 3) {
            rotate(num, dir);
            if (third) {
                rotate(2, -dir);
                if (second) {
                    rotate(1, dir);
                    if (first) {
                        rotate(0, -dir);
                    }
                }
            }
        }
     }
//    for(auto & i : gear) {
//        for(auto & j : i) {
//            cout << j;
//        }
//        cout << endl << endl;
//    }

    cout << gear[0][0] * 1 + gear[1][0] * 2 + gear[2][0] * 4 + gear[3][0] * 8;
}
