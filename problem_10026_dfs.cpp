#include <iostream>
#include <vector>

using namespace std;

int N, result1 = 0, result2 = 0;
vector<vector<char>> map;
bool visited[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool move(int n, int m) {
    if(n < N && n >= 0 && m < N && m >= 0)
        return true;
    return false;
}

void dfs_1(int r, int c, char color) {
    if(visited[r][c] || !move(r, c)) {
        return;
    }

    visited[r][c] = true;

    for(int i = 0; i < 4; i++) {
        int nx = r + dx[i];
        int ny = c + dy[i];

        if(move(nx, ny) && !visited[nx][ny] && map[nx][ny] == color) {
            dfs_1(nx, ny, color);
        }
    }

}

void dfs_2(int r, int c, char color) {
    if(!visited[r][c] || !move(r, c)) {
        return;
    }

    visited[r][c] = false;

    for(int i = 0; i < 4; i++) {
        int nx = r + dx[i];
        int ny = c + dy[i];

        if(move(nx, ny) && visited[nx][ny]) {
            if ((map[r][c] == 'R' || map[r][c] == 'G') && (map[nx][ny] == 'R' || map[nx][ny] == 'G')) {
                dfs_2(nx, ny, color);
            }
            else if(map[r][c] == 'B' && map[nx][ny] == 'B') {
                dfs_2(nx, ny, color);
            }
        }
    }

}

int main() {
    cin >> N;
    map.resize(N, vector<char>(N, 0));

    string temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        for(int j = 0; j < N; j++) {
            map[i][j] = temp[j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs_1(i, j, map[i][j]);
                result1++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (visited[i][j]) {
                dfs_2(i, j, map[i][j]);
                result2++;
            }
        }
    }

    cout << result1 << " " << result2;
//    for(auto & ptr : map) {
//        for(auto & p : ptr) {
//            cout << p;
//        }
//        cout << endl;
//    }
}
