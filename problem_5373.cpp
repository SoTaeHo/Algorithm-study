#include <iostream>
#include <vector>
//#include <cstring>
using namespace std;

char original[6][3][3] = {
        {
                {'w', 'w', 'w'},
                {'w', 'w', 'w'},
                {'w', 'w', 'w'}
        },
        {
                {'y', 'y', 'y'},
                {'y', 'y', 'y'},
                {'y', 'y', 'y'},
        },
        {
                {'r', 'r', 'r'},
                {'r', 'r', 'r'},
                {'r', 'r', 'r'},
        },
        {
                {'o', 'o', 'o'},
                {'o', 'o', 'o'},
                {'o', 'o', 'o'},
        },
        {
                {'g', 'g', 'g'},
                {'g', 'g', 'g'},
                {'g', 'g', 'g'},
        },
        {
                {'b', 'b', 'b'},
                {'b', 'b', 'b'},
                {'b', 'b', 'b'},
        },

};

char cube[6][3][3] = {
        {
                {'w', 'w', 'w'},
                {'w', 'w', 'w'},
                {'w', 'w', 'w'}
        },
        {
                {'y', 'y', 'y'},
                {'y', 'y', 'y'},
                {'y', 'y', 'y'},
        },
        {
                {'r', 'r', 'r'},
                {'r', 'r', 'r'},
                {'r', 'r', 'r'},
        },
        {
                {'o', 'o', 'o'},
                {'o', 'o', 'o'},
                {'o', 'o', 'o'},
        },
        {
                {'g', 'g', 'g'},
                {'g', 'g', 'g'},
                {'g', 'g', 'g'},
        },
        {
                {'b', 'b', 'b'},
                {'b', 'b', 'b'},
                {'b', 'b', 'b'},
        },

};

void resetCube() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cube[i][j][k] = original[i][j][k];
            }
        }
    }
}

void clockwise(int i) {
    // 시계 회전
    char temp[3][3] = {{cube[i][2][0], cube[i][1][0], cube[i][0][0]},
                       {cube[i][2][1], cube[i][1][1], cube[i][0][1]},
                       {cube[i][2][2], cube[i][1][2], cube[i][0][2]}
    };
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            cube[i][j][k] = temp[j][k];
        }
    }
}

void inverted(int i) {
    // 반시계 회전
    char temp[3][3] = {
            {cube[i][0][2], cube[i][1][2], cube[i][2][2]},
            {cube[i][0][1], cube[i][1][1], cube[i][2][1]},
            {cube[i][0][0], cube[i][1][0], cube[i][2][0]}
    };
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            cube[i][j][k] = temp[j][k];
        }
    }
}

int n;

void shift(char face, char way) {
    if (face == 'U') {
        if (way == '+') {
            // 윗방향을 시계방향으로 돌리면 F > L, L > B, B > R, R > F
            // 마지막 방향을 임시변수에 저장해놓고 회전
            char f = cube[2][0][0];
            char s = cube[2][0][1];
            char t = cube[2][0][2];
            // R > F
            cube[2][0][0] = cube[5][0][0];
            cube[2][0][1] = cube[5][0][1];
            cube[2][0][2] = cube[5][0][2];
            // B > R
            cube[5][0][0] = cube[3][0][0];
            cube[5][0][1] = cube[3][0][1];
            cube[5][0][2] = cube[3][0][2];
            // L > B
            cube[3][0][0] = cube[4][0][0];
            cube[3][0][1] = cube[4][0][1];
            cube[3][0][2] = cube[4][0][2];
            // F > L
            cube[4][0][0] = f;
            cube[4][0][1] = s;
            cube[4][0][2] = t;
            clockwise(0);
        } else if (way == '-') {
            // 윗방향을 반시계방향으로 돌리면 F > R, R > B, B > L, L > F
            // U : 흰색(0) , D : 노랑(1), F : 빨강(2), B: 오렌지(3), L : 초록(4), R : 파랑(5)
            char f = cube[2][0][0];
            char s = cube[2][0][1];
            char t = cube[2][0][2];

            // L > F
            cube[2][0][0] = cube[4][0][0];
            cube[2][0][1] = cube[4][0][1];
            cube[2][0][2] = cube[4][0][2];
            // B > L
            cube[4][0][0] = cube[3][0][0];
            cube[4][0][1] = cube[3][0][1];
            cube[4][0][2] = cube[3][0][2];
            // R > B
            cube[3][0][0] = cube[5][0][0];
            cube[3][0][1] = cube[5][0][1];
            cube[3][0][2] = cube[5][0][2];
            // F > R
            cube[5][0][0] = f;
            cube[5][0][1] = s;
            cube[5][0][2] = t;
            inverted(0);
        }
    } else if (face == 'D') {
        if (way == '+') {
            // 아래방향을 시계방향으로 돌리면 F > L, L > B, B > R, R > F
            // 마지막 방향을 임시변수에 저장해놓고 회전
            char f = cube[2][2][0];
            char s = cube[2][2][1];
            char t = cube[2][2][2];

            // L > F
            cube[2][2][0] = cube[4][2][0];
            cube[2][2][1] = cube[4][2][1];
            cube[2][2][2] = cube[4][2][2];
            // B > L
            cube[4][2][0] = cube[3][2][0];
            cube[4][2][1] = cube[3][2][1];
            cube[4][2][2] = cube[3][2][2];
            // R > B
            cube[3][2][0] = cube[5][2][0];
            cube[3][2][1] = cube[5][2][1];
            cube[3][2][2] = cube[5][2][2];
            // F > R
            cube[5][2][0] = f;
            cube[5][2][1] = s;
            cube[5][2][2] = t;

            clockwise(1);
        } else if (way == '-') {
            // 아랫방향을 반시계방향으로 돌리면 F > R, R > B, B > L, L > F
            // 마지막 방향을 임시변수에 저장해놓고 회전
            char f = cube[2][2][0];
            char s = cube[2][2][1];
            char t = cube[2][2][2];

            // R > F
            cube[2][2][0] = cube[5][2][0];
            cube[2][2][1] = cube[5][2][1];
            cube[2][2][2] = cube[5][2][2];
            // B > R
            cube[5][2][0] = cube[3][2][0];
            cube[5][2][1] = cube[3][2][1];
            cube[5][2][2] = cube[3][2][2];
            // L > B
            cube[3][2][0] = cube[4][2][0];
            cube[3][2][1] = cube[4][2][1];
            cube[3][2][2] = cube[4][2][2];
            // F > L
            cube[4][2][0] = f;
            cube[4][2][1] = s;
            cube[4][2][2] = t;
            inverted(1);
        }
    } else if (face == 'F') {
        if (way == '+') {
            // 앞방향을 시계방향으로 돌리면 U > R, R > D, D > L, L > U
            char f = cube[0][2][0];
            char s = cube[0][2][1];
            char t = cube[0][2][2];
            // L > U
            cube[0][2][0] = cube[4][2][2];
            cube[0][2][1] = cube[4][1][2];
            cube[0][2][2] = cube[4][0][2];
            // D > L
            cube[4][0][2] = cube[1][0][0];
            cube[4][1][2] = cube[1][0][1];
            cube[4][2][2] = cube[1][0][2];
            // R > D
            cube[1][0][0] = cube[5][2][0];
            cube[1][0][1] = cube[5][1][0];
            cube[1][0][2] = cube[5][0][0];
            // U > R
            cube[5][0][0] = f;
            cube[5][1][0] = s;
            cube[5][2][0] = t;
            clockwise(2);
        } else if (way == '-') {
            // 앞방향을 반시계방향으로 돌리면 U > L, L > D, D > R, R > U
            char f = cube[0][2][0];
            char s = cube[0][2][1];
            char t = cube[0][2][2];
            // R > U
            cube[0][2][0] = cube[5][0][0];
            cube[0][2][1] = cube[5][1][0];
            cube[0][2][2] = cube[5][2][0];
            // D > R
            cube[5][0][0] = cube[1][0][2];
            cube[5][1][0] = cube[1][0][1];
            cube[5][2][0] = cube[1][0][0];
            // L > D
            cube[1][0][0] = cube[4][0][2];
            cube[1][0][1] = cube[4][1][2];
            cube[1][0][2] = cube[4][2][2];
            // U > L
            cube[4][0][2] = t;
            cube[4][1][2] = s;
            cube[4][2][2] = f;
            inverted(2);
        }
    } else if (face == 'B') {
        if (way == '+') {
            // 뒷방향을 시계방향으로 돌리면 U > L, L > D, D > R, R > U
            char f = cube[0][0][0];
            char s = cube[0][0][1];
            char t = cube[0][0][2];
            // R > U
            cube[0][0][0] = cube[5][0][2];
            cube[0][0][1] = cube[5][1][2];
            cube[0][0][2] = cube[5][2][2];
            // D > R
            cube[5][0][2] = cube[1][2][2];
            cube[5][1][2] = cube[1][2][1];
            cube[5][2][2] = cube[1][2][0];
            // L > D
            cube[1][2][0] = cube[4][0][0];
            cube[1][2][1] = cube[4][1][0];
            cube[1][2][2] = cube[4][2][0];
            // U > L
            cube[4][0][0] = t;
            cube[4][1][0] = s;
            cube[4][2][0] = f;
            clockwise(3);
        } else if (way == '-') {
            // 뒷방향을 반시계방향으로 돌리면 U > R, R > D, D > L, L > U
            char f = cube[0][0][0];
            char s = cube[0][0][1];
            char t = cube[0][0][2];
            // L > U
            cube[0][0][0] = cube[4][2][0];
            cube[0][0][1] = cube[4][1][0];
            cube[0][0][2] = cube[4][0][0];
            // D > L
            cube[4][0][0] = cube[1][2][0];
            cube[4][1][0] = cube[1][2][1];
            cube[4][2][0] = cube[1][2][2];
            // R > D
            cube[1][2][0] = cube[5][2][2];
            cube[1][2][1] = cube[5][1][2];
            cube[1][2][2] = cube[5][0][2];
            // U > R
            cube[5][0][2] = f;
            cube[5][1][2] = s;
            cube[5][2][2] = t;
            inverted(3);
        }
    } else if (face == 'L') {
        if (way == '+') {
            // 왼쪽방향을 시계방향으로 돌리면 U > F, F > D, D > B, B > U
            // U : 흰색(0) , D : 노랑(1), F : 빨강(2), B: 오렌지(3), L : 초록(4), R : 파랑(5)

            char f = cube[0][0][0];
            char s = cube[0][1][0];
            char t = cube[0][2][0];
            // B > U
            cube[0][0][0] = cube[3][2][2];
            cube[0][1][0] = cube[3][1][2];
            cube[0][2][0] = cube[3][0][2];
            // D > B
            cube[3][0][2] = cube[1][2][0];
            cube[3][1][2] = cube[1][1][0];
            cube[3][2][2] = cube[1][0][0];
            // F > D
            cube[1][0][0] = cube[2][0][0];
            cube[1][1][0] = cube[2][1][0];
            cube[1][2][0] = cube[2][2][0];
            // U > F
            cube[2][0][0] = f;
            cube[2][1][0] = s;
            cube[2][2][0] = t;
            clockwise(4);
        } else if (way == '-') {
            // 왼쪽방향을 반시계방향으로 돌리면 U > B, B > D, D > F, F > U
            // U : 흰색(0) , D : 노랑(1), F : 빨강(2), B: 오렌지(3), L : 초록(4), R : 파랑(5)

            char f = cube[0][0][0];
            char s = cube[0][1][0];
            char t = cube[0][2][0];
            // F > U
            cube[0][0][0] = cube[2][0][0];
            cube[0][1][0] = cube[2][1][0];
            cube[0][2][0] = cube[2][2][0];
            // D > F
            cube[2][0][0] = cube[1][0][0];
            cube[2][1][0] = cube[1][1][0];
            cube[2][2][0] = cube[1][2][0];
            // B > D
            cube[1][0][0] = cube[3][2][2];
            cube[1][1][0] = cube[3][1][2];
            cube[1][2][0] = cube[3][0][2];
            // U > B
            cube[3][2][2] = f;
            cube[3][1][2] = s;
            cube[3][0][2] = t;
            inverted(4);
        }
    } else if (face == 'R') {
        if (way == '+') {
            // 오른쪽 방향을 시계방향으로 돌리면 U > B, B > D, D > F, F > U
            // U : 흰색(0) , D : 노랑(1), F : 빨강(2), B: 오렌지(3), L : 초록(4), R : 파랑(5)

            char f = cube[0][0][2];
            char s = cube[0][1][2];
            char t = cube[0][2][2];
            // F > U
            cube[0][0][2] = cube[2][0][2];
            cube[0][1][2] = cube[2][1][2];
            cube[0][2][2] = cube[2][2][2];
            // D > F
            cube[2][0][2] = cube[1][0][2];
            cube[2][1][2] = cube[1][1][2];
            cube[2][2][2] = cube[1][2][2];
            // B > D
            cube[1][0][2] = cube[3][2][0];
            cube[1][1][2] = cube[3][1][0];
            cube[1][2][2] = cube[3][0][0];
            // U > B
            cube[3][2][0] = f;
            cube[3][1][0] = s;
            cube[3][0][0] = t;
            clockwise(5);
        }
        if (way == '-') {
            // 오른쪽방향을 반시계방향으로 돌리면 U > F, F > D, D > B, B > U
            char f = cube[0][0][2];
            char s = cube[0][1][2];
            char t = cube[0][2][2];
            // B > U
            cube[0][0][2] = cube[3][2][0];
            cube[0][1][2] = cube[3][1][0];
            cube[0][2][2] = cube[3][0][0];
            // D > B
            cube[3][0][0] = cube[1][2][2];
            cube[3][1][0] = cube[1][1][2];
            cube[3][2][0] = cube[1][0][2];
            // F > D
            cube[1][0][2] = cube[2][0][2];
            cube[1][1][2] = cube[2][1][2];
            cube[1][2][2] = cube[2][2][2];
            // U > F
            cube[2][0][2] = f;
            cube[2][1][2] = s;
            cube[2][2][2] = t;
            inverted(5);
        }
    }
}

int main() {
    // U : 흰색(0) , D : 노랑(1), F : 빨강(2), B: 오렌지(3), L : 초록(4), R : 파랑(5)

    cin >> n;

    // n개의 테스트 케이스 반복
    for (int i = 0; i < n; i++) {
        // 반복할 횟수 입력
        int count;
        cin >> count;

        // 방법 입력
        vector<string> arr;
        for (int j = 0; j < count; j++) {
            string temp;
            cin >> temp;
            arr.emplace_back(temp);
        }
        // 큐브 돌리기
        int ak = 1;
        for (auto &str: arr) {
            shift(str[0], str[1]);
//            cout << ak++ << endl;
            // 맨 윗면만 봄
//            for (int j = 0; j < 3; j++) {
//                for (int k = 0; k < 3; k++) {
//                    cout << cube[0][j][k];
//                }
//                cout << endl;
//            }

////            6면 다봄
//            for (auto &i: cube) {
//                for (auto &j: i) {
//                    for (char k: j) {
//                        cout << k;
//                    }
//                    cout << endl;
//                }
//                cout << endl;
//            }

        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << cube[0][j][k];
            }
            cout << endl;
        }
;
        resetCube();
    }
//    for (auto &i: cube) {
//        for (auto &j: i) {
//            for (char k: j) {
//                cout << k << ' ';
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }

}