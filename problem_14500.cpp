#include "iostream"
#include "vector"

using namespace std;

int n, m;
int result = 0;
vector<vector<int>> map;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0,0, 1, -1};

void find_way(int x, int y, int cnt, int sum, vector<int> temp) {
    if (cnt == 4) {
        if (sum > result) {
            result = sum;
            for(auto &ptr : temp) {
                cout << ptr << ' ';
            }
            cout << '\n';
        }
        return;
    }

    if(x < 0 || y < 0 || x > n || y > n) {
        return;
    }

    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            temp.push_back(map[x][y]);
            find_way(nx, ny, cnt + 1, sum + map[x][y], temp);
        }
    }
}

int main(void) {
    cin >> n >> m;
    map.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<int> temp;
            find_way(i, j, 0, 0, temp);
        }
    }
    cout << result;
}