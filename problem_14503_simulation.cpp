#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, r, c, d, result = 0;
bool power = 1;
vector<vector<int>> map;

bool move(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    return true;
}

void dfs(int x, int y){

    if (!move(x, y) || map[x][y] == 1 || !power)
        return;

    // 1. 현재 칸 청소
    if (map[x][y] == 0) {
        map[x][y] = 2;
        result++;
    }
    bool empty = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (move(nx, ny) && map[nx][ny] == 0) {
            empty = true;
        }
    }
    if (!empty) {
        if(move(x - dx[d], y - dy[d]) && map[x - dx[d]][y - dy[d]] != 1) {
            dfs(x - dx[d], y - dy[d]);
        } else {
            power = false;
        }
    } else {
        // 북0 동1 남2 서3 => 0 -> 3, 1 -> 0,
        d = d - 1;
        if (d < 0)
            d = 3;
        if (move(x + dx[d], y + dy[d]) && map[x + dx[d]][y + dy[d]] == 0) {
            dfs(x + dx[d], y + dy[d]);
        } else {
            dfs(x, y);
        }
    }
}

int main(void) {
    cin >> n >> m >> r >> c >> d;

    map.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    dfs(r, c);

    cout << result;

}