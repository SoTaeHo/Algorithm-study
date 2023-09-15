#include "iostream"
#include "vector"
#include "queue"
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<vector<int>> q;
bool visited[10][10][10][10];
vector<vector<char>> map;

void bfs() {
    int nx_r;
    int ny_r;
    int nx_b;
    int ny_b;
    int cnt;
    while(!q.empty()) {
        vector<int> vec = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx_r = vec[0];
            ny_r = vec[1];
            nx_b = vec[2];
            ny_b = vec[3];
            cnt = vec[4] + 1;
            int distance = 0;

            bool b_out = false;
            if (cnt > 10) {
                cout << -1;
                return;
            }
            while (map[nx_b + dx[i]][ny_b + dy[i]] != '#') {

                nx_b += dx[i];
                ny_b += dy[i];
                distance++;
                if (map[nx_b][ny_b] == 'O') {
                    b_out = true;
                }
            }

            if (b_out)
                continue;

            while (map[nx_r + dx[i]][ny_r + dy[i]] != '#') {
                nx_r += dx[i];
                ny_r += dy[i];
                distance--;
                if (map[nx_r][ny_r] == 'O') {
                    if (cnt <= 10) {
                        cout << cnt;
                        return;
                    } else {
                        cout << -1;
                        return;
                    }
                }
            }

            // 동일한 행 또는 동일한 열에서 이동할 경우 움직인 거리에 따라 많이 움직인 구슬의 위치를 조정해준다
            if (nx_r == nx_b && ny_r == ny_b) {
                if (distance > 0) {
                    nx_b -= dx[i];
                    ny_b -= dy[i];
                }
                else if (distance < 0) {
                    nx_r -= dx[i];
                    ny_r -= dy[i];
                }
            }

            // 이미 방문했던 경로에 다시 방문을 해야하는 해의 경우 어떻게 처리를 해야할까
            // - 현재는 이미 방문했던 곳은 현재 진행한 횟수보다 많은 횟수로 도달하면 방문처리를 하지 않음
            // 이미 존재했던 R과 B의 위치 >> 다시 돌아올 수 있는 곳 >> 큐에 집어넣지 않음

            if (!visited[nx_r][ny_r][nx_b][ny_b]) {
                if (map[nx_r][ny_r] == 'O') {
                    if (cnt <= 10) {
                        cout << cnt;
                        return;
                    }
                    else {
                        cout << -1;
                        return;
                    }
                }
                visited[nx_r][ny_r][nx_b][ny_b] = true;
                q.push({nx_r, ny_r, nx_b, ny_b, cnt});
            }
        }
    }
    cout << -1;
}

int main (void) {
    int n, m;

    cin >> n >> m;

    map.resize(n, vector<char>(m, 0));
    int rx, ry, bx, by;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            else if (map[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }
    visited[rx][ry][bx][by] = true;
    q.push({rx, ry, bx, by, 0});
//    1. bfs를 실행할 때 갈 수 있는 만큼 이동
    bfs();
//    2. O를 만나면 종료 / 두 구슬이 같은 칸에 있을 수 없음
//    3. -1이 되는 경우 : R이 O에 도달할 수 없을 때 / R과 B가 동시에 O에 도달할 때 / B가 먼저 O에 도달할 때

//    // print vector
//    for (auto & ptr : map) {
//        for (auto & p : ptr) {
//            cout << p;
//        }
//        cout << '\n';
//    }
}
