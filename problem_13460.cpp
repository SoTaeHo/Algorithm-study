#include "iostream"
#include "vector"
#include "queue"
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> r_q;
queue<pair<int, int>> b_q;
vector<vector<int>> visited;
vector<vector<char>> map;

pair<int, int> r;
pair<int, int> b;
pair<int, int> o;

void bfs() {
    cout << "bfs start\n";
    int nx_r;
    int ny_r;
    int nx_b;
    int ny_b;

    // back traking
    while(!r_q.empty()) {
        r = r_q.front();
        r_q.pop();

        b = b_q.front();
        b_q.pop();

        for (int i = 0; i < 4; i++) {
            nx_r = r.first;
            ny_r = r.second;
            nx_b = b.first;
            ny_b = b.second;
            int distance = 0;
            // 가려는 방향이 바로 벽으로 막히면 다음 방향으로 continue
            if (visited[nx_r + dx[i]][ny_r + dy[i]] == -1) {
                continue;
            }
            while (map[nx_b + dx[i]][ny_r + dy[i]] != '#') {
                nx_b += dx[i];
                ny_b += dy[i];
                distance++;
                if (map[nx_b][ny_b] == 'O') {
                    cout << -1;
                    return;
                }
            }
            while (map[nx_r + dx[i]][ny_r + dy[i]] != '#') {
                nx_r += dx[i];
                ny_r += dy[i];
                distance--;
                if (map[nx_r][ny_r] == 'O') {
                    cout << visited[r.first][r.second] + 1;
                    return;
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


            if (visited[nx_r][ny_r] > visited[r.first][r.second] + 1 || visited[nx_r][ny_r] == 0) {
                visited[nx_r][ny_r] = visited[r.first][r.second] + 1;
                if (map[nx_r][ny_r] == 'O') {
                    cout << visited[nx_r][ny_r];
                    return;
                }
                r_q.emplace(nx_r, ny_r);
            }
        }
    }
    cout << -1;
}

int main (void) {
    int n, m;

    cin >> n >> m;

    visited.resize(n , vector<int>(m, 0));
    map.resize(n, vector<char>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '#')
                visited[i][j] = -1;
            else if (map[i][j] == 'R') {
                r = make_pair(i, j);
                r_q.push(r);
            }
            else if (map[i][j] == 'B') {
                b = make_pair(i, j);
                b_q.push(b);
            }
            else if (map[i][j] == 'O')
                o = make_pair(i, j);
        }
    }

//    1. bfs를 실행할 때 갈 수 있는 만큼 이동
    bfs();
//    2. O를 만나면 종료 / 두 구슬이 같은 칸에 있을 수 없음
//    3. -1이 되는 경우 : R이 O에 도달할 수 없을 때 / R과 B가 동시에 O에 도달할 때 / B가 먼저 O에 도달할 때

    // print vector
    for (auto & ptr : map) {
        for (auto & p : ptr) {
            cout << p;
        }
        cout << '\n';
    }

}