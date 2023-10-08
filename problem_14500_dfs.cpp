#include "iostream"
#include "vector"

using namespace std;

int n, m;
int result = 0;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void find_way(int x, int y, int cnt, int sum) {
    if (cnt == 4) {
        if (sum > result) {
            result = sum;
        }
        return;
    }

    if ((x < 0 || y < 0 || x >= n || y >= m)) {
        return;
    }

    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
            visited[nx][ny] = true;
            find_way(nx, ny, cnt + 1, sum + map[x][y]);
            visited[nx][ny] = false;
        }
    }
}

void exception_block(int x, int y) {
    int temp = map[x][y];
    int nx;
    int ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            temp += map[nx][ny];
        }
    }
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (temp - map[nx][ny] > result) {
                result = temp - map[nx][ny];
            }
        } else {
            if (temp > result)
                result = temp;
        }
    }
}

int main(void) {
    cin >> n >> m;
    map.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            find_way(i, j, 0, 0);
            visited[i][j] = false;
            exception_block(i, j);
        }
    }
    cout << result;
}