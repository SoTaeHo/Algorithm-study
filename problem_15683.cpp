#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

int N, M, result = 0;
vector<int> cctv;
vector<pair<int, int>> cor;
vector<vector<int>> copymap;

void check(vector<vector<int>> temp) {
    for (int i = 0; i < cctv.size(); i++) {
        int x = cor[i].first;
        int y = cor[i].second;

        if (temp[x][y] == 1) { // cctv의 종류가 1이면 1방향
            if (cctv[i] == 0) { // cctv가 0이면 위, 1이면 오른쪽, 2면 아래, 3이면 왼쪽
                while (true) {
                    x--;
                    if (x < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            } else if (cctv[i] == 1) { // 오른쪽
                while (true) {
                    y++;
                    if (y >= M || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            } else if (cctv[i] == 2) { // 1번의 아래
                while (true) {
                    x++;
                    if (x >= N || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            } else if (cctv[i] == 3) { // 1번의 왼쪽
                while (true) {
                    y--;
                    if (y < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            }
        }
        else if (temp[x][y] == 2) { // 양방향
            if (cctv[i] == 0 || cctv[i] == 2) { // 0이면 좌우
                while (true) {
                    y--;
                    if (y < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                y = cor[i].second;
                while (true) {
                    y++;
                    if (y >= M || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            }
            else if (cctv[i] == 1 || cctv[i] == 3) { // 1이면 상하
                while (true) {
                    x++;
                    if (x >= N || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                x = cor[i].first;
                while (true) {
                    x--;
                    if (x < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            }
        }
        else if (temp[x][y] == 3) { // 3이면 직각
            if (cctv[i] == 0) { // cctv가 0이면 북동, 1이면 남동, 2면 남서, 3이면 북동
                while (true) { // up
                    x--;
                    if (x < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                x = cor[i].first;
                while (true) { // right
                    y++;
                    if (y >= M || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }

            } else if (cctv[i] == 1) { // 남동
                while (true) { // right
                    y++;
                    if (y >= M || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                y = cor[i].second;
                while (true) { // down
                    x++;
                    if (x >= N || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            } else if (cctv[i] == 2) { // 남서
                while (true) { // down
                    x++;
                    if (x >= N || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                x = cor[i].first;
                while (true) { // left
                    y--;
                    if (y < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            } else if (cctv[i] == 3) { // 북서
                while (true) { // left
                    y--;
                    if (y < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                y = cor[i].second;
                while (true) { // up
                    x--;
                    if (x < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            }
        }
        else if (temp[x][y] == 4) {
            if (cctv[i] == 0) { // 1곳만 비는 cctv
                while (true) {
                    y++;
                    if (y >= M || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                y = cor[i].second;
                while (true) {
                    y--;
                    if (y < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                y = cor[i].second;
                while (true) {
                    x++;
                    if (x >= N || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            } else if (cctv[i] == 1) { // 왼쪽이 비는 경우
                while (true) {
                    x--;
                    if (x < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                x = cor[i].first;
                while (true) {
                    y++;
                    if (y >= M || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                y = cor[i].second;
                while (true) {
                    x++;
                    if (x >= N || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            } else if (cctv[i] == 2) { // 위가 비는 경우
                while (true) {
                    y++;
                    if (y >= M || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                y = cor[i].second;
                while (true) {
                    y--;
                    if (y < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                y = cor[i].second;
                while (true) {
                    x--;
                    if (x < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            } else if (cctv[i] == 3) { // 오른쪽이 비는 경우
                while (true) {
                    x--;
                    if (x < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                x = cor[i].first;
                while (true) {
                    y--;
                    if (y < 0 || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
                y = cor[i].second;
                while (true) {
                    x++;
                    if (x >= N || temp[x][y] == 6)
                        break;
                    if (temp[x][y] != 0)
                        continue;
                    temp[x][y] = 7;
                }
            }
        }
        else if (temp[x][y] == 5) { // 모든 방향
            while (true) {
                x--;
                if (x < 0 || temp[x][y] == 6)
                    break;
                if (temp[x][y] != 0)
                    continue;
                temp[x][y] = 7;
            }
            x = cor[i].first;
            while (true) {
                y++;
                if (y >= M || temp[x][y] == 6)
                    break;
                if (temp[x][y] != 0)
                    continue;
                temp[x][y] = 7;
            }
            y = cor[i].second;
            while (true) {
                y--;
                if (y < 0 || temp[x][y] == 6)
                    break;
                if (temp[x][y] != 0)
                    continue;
                temp[x][y] = 7;
            }
            y = cor[i].second;
            while (true) {
                x++;
                if (x >= N || temp[x][y] == 6)
                    break;
                if (temp[x][y] != 0)
                    continue;
                temp[x][y] = 7;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (temp[i][j] == 0)
                sum++;
        }
    }
    if (sum < result) {
        result = sum;
        copymap = temp;
    }
}

void next(vector<vector<int>> temp) {
    cctv[0]++;
    for(int i = 0; i < cctv.size() - 1; i++) {
        if (cctv[i] == 4) {
            cctv[i] = 0;
            cctv[i + 1]++;
        }
    }
//    cout << cctv[0] << " " << cctv[1] << " " << cctv[2] << endl;
}


int main() {
    cin >> N >> M;

    vector<vector<int>> map;
    map.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                result++;
            }
            if (map[i][j] != 0 && map[i][j] != 6) {
                cctv.push_back(0);
                cor.emplace_back(i, j);
            }
        }
    }
//    for(auto & ptr : cor) {
//        cout << ptr.first << " " << ptr.second << endl;
//    }
//    cout << cctv.size() << " " << pow(4, cctv.size()) << endl;

    if (cctv.size() == 0) {
        cout << result;
        return 0;
    }
    for (int i = 0; i < pow(4, cctv.size()); i++) {
        check(map);
        next(map);
    }
//    for(auto & i : copymap) {
//        for(auto & j : i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
    cout << result;
}