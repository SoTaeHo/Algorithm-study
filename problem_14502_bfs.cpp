#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, result = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool moved(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    return true;
}

int bfs(vector<vector<int>> map, queue<pair<int, int>> q, int safe, int i, int j, int k) {
    if (map[i / m][i % m] != 0 || map[j / m][j % m] != 0 || map[k / m][k % m] != 0)
        return 0;
    map[i / m][i % m] = 1;
    map[j / m][j % m] = 1;
    map[k / m][k % m] = 1;

    while(!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = temp.first + dx[i];
            int ny = temp.second + dy[i];
            if(moved(nx, ny) && map[nx][ny] == 0) {
                q.emplace(nx, ny);
                safe--;
                map[nx][ny] = 2;
            }
        }
    }
    return safe;
}

int main(void) {
    cin >> n >> m;
    vector<vector<int>> map;
    queue<pair<int, int>> q;
    vector<vector<int>> new_map;

    map.resize(n, vector<int>(m, 0));
    int safe = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                safe++;
            } else if (map[i][j] == 2) {
                q.emplace(i, j);
            }
        }
    }
    for(int i = 0; i < n * m; i++) {
        for(int j = i + 1; j < n * m; j++) {
            for(int k = j + 1; k < n * m; k++) {
                int temp = bfs(map, q, safe - 3, i, j, k);
                if(temp > result) {
                    result = temp;
                }
            }
        }
    }
    cout << result;
}
