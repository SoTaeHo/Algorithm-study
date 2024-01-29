#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L, result = 0;
vector<vector<int>> map;
vector<vector<bool>> check;
int main(){
    cin >> N >> L;

    map.resize(N, vector<int>(N, 0));
    check.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        int cur = map[i][0];
        for(int j = 1; j < N; j++) {
            // 1. 현재 높이와 같으면 진행
            if (map[i][j] == cur) {
                cur = map[i][j];
                if (j == N - 1) {
                    result++;
                }
                continue;
            }
            // 2. 높이 차가 1이 아니면 중단
            if (abs(map[i][j] - cur) != 1)
                break;
            // 3. 내리막
            else if (cur - map[i][j] == 1) {
                bool place = true;
                for (int k = 0; k < L; k++) {
                    if (j + k >= N || map[i][j] != map[i][j + k]) {
                        place = false;
                        break;
                    }
                    // 경사로가 놓여있으면 중단
                    if (check[i][j + k]) {
                        place = false;
                        break;
                    }
                    check[i][j + k] = true;
                }
                // 경사로가 L개가 이어지지 않는 경우, 이미 경사로가 놓여져 있는 경우
                if (!place) {
                    break;
                }
            }
            // 4. 오르막
            else if (cur - map[i][j] == -1) {
                bool place = true;
                for (int k = 0; k < L; k++) {
                    if (j - k - 1 < 0 || cur != map[i][j - k - 1]) {
                        place = false;
                        break;
                    }
                    if (check[i][j - k - 1]) {
                        place = false;
                        break;
                    }
                    check[i][j - k - 1] = true;
                }
                // 경사로가 L개가 이어지지 않는 경우, 이미 경사로가 놓여져 있는 경우
                if (!place) {
                    break;
                }
            }

            cur = map[i][j];

            if (j == N - 1)
                result++;
        }
    }

    check.clear();
    check.resize(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++) {
        int cur = map[0][i];
        for(int j = 1; j < N; j++) {
            // 1. 현재 높이와 같으면 진행
            if (map[j][i] == cur) {
                cur = map[j][i];
                if (j == N - 1) {
                    result++;
                }
                continue;
            }
            // 2. 높이 차가 1이 아니면 중단
            if (abs(map[j][i] - cur) != 1)
                break;
                // 3. 내리막
            else if (cur - map[j][i] == 1) {
                bool place = true;
                for (int k = 0; k < L; k++) {
                    if (j + k >= N || map[j][i] != map[j + k][i]) {
                        place = false;
                        break;
                    }
                    // 경사로가 놓여있으면 중단
                    if (check[j + k][i]) {
                        place = false;
                        break;
                    }
                    check[j + k][i] = true;
                }
                // 경사로가 L개가 이어지지 않는 경우, 이미 경사로가 놓여져 있는 경우
                if (!place)
                    break;
            }
                // 4. 오르막
            else if (cur - map[j][i] == -1) {
                bool place = true;
                for (int k = 0; k < L; k++) {
                    if (j - k - 1 < 0 || cur != map[j - k - 1][i]) {
                        place = false;
                        break;
                    }
                    if (check[j - k - 1][i]) {
                        place = false;
                        break;
                    }
                    check[j - k - 1][i] = true;
                }
                // 경사로가 L개가 이어지지 않는 경우, 이미 경사로가 놓여져 있는 경우
                if (!place)
                    break;
            }

            cur = map[j][i];

            if (j == N - 1)
                result++;
        }
    }
    cout << result;
}