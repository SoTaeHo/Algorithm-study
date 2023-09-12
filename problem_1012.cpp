#include "iostream"
#include "vector"
#include "stack"

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int>> map;
stack<pair<int, int>> s;

bool is_valid(int x, int y, int row, int col) {
    return (x < row && x >= 0 && y < col && y >= 0);
}

bool bfs(int row, int col) {
    int nx;
    int ny;
    bool can_move = is_valid(row, col, map.size(), map[0].size());

    if (!can_move || map[row][col] == 0) {
        return false;
    }

    map[row][col] = 0;

    for (int i = 0; i < 4; i++) {
        nx = row + dx[i];
        ny = col + dy[i];

        if (is_valid(nx, ny, map.size(), map[0].size()) && map[nx][ny] == 1) {
            bfs(nx, ny);
        }
    }

    return true;
}

void bfs_stack(int row, int col) {
    int nx;
    int ny;

    map[row][col] = 0;
    s.emplace(row, col);

    while (!s.empty()) {
        pair<int, int> p = s.top();
        s.pop();
        for (int i = 0; i < 4; i++) {
            nx = p.first + dx[i];
            ny = p.second + dy[i];

            if (is_valid(nx, ny, map.size(), map[0].size()) && map[nx][ny] == 1) {
                map[nx][ny] = 0;
                s.emplace(nx, ny);
            }
        }
    }
}

int main(void) {
    int t, m, n, k, row, col, result = 0;

    cin >> t;

    while (t > 0) {
        cin >> m >> n >> k;

//        for (int i = 0; i < n; i++) {
//            vector<int> temp;
//            for (int j = 0; j < m; j++) {
//                temp.push_back(0);
//            }
//            map.push_back(temp);
//        }
        map.clear();
        map.resize(n, vector<int>(m, 0));
        for (int i = 0; i < k; i++) {
            cin >> col >> row;
            map[row][col] = 1;
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
//                if (map[i][j] == 1 && bfs(i, j)) {
//                    result++;
//                }
                if (map[i][j] == 1) {
                    bfs_stack(i, j);
                    result++;
//                    for (auto & ptr : map) {
//                        for (auto & p : ptr) {
//                            cout << p;
//                        }
//                        cout << '\n';
//                    }
                }
            }
        }

//        for (auto & ptr : map) {
//            for (auto & p : ptr) {
//                cout << p;
//            }
//            cout << '\n';
//        }

        cout << result << '\n';
        result = 0;
        t--;
    }


}