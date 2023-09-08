#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool is_valid(int x, int y, int i, int j) {
    return (x > i && i >= 0 && y > j && j >= 0);
}

void bfs(vector<vector<int>> box, queue<pair<int, int>> &q) {
    int nx;
    int ny;
    int result = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = p.first + dx[i];
            ny = p.second + dy[i];
            if (is_valid(box.size(), box[0].size(), nx, ny) && box[nx][ny] == 0) {
                box[nx][ny] = box[p.first][p.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    for (int i = 0; i < box.size(); i++) {
        for (int j = 0; j < box[0].size(); j++) {
            if (box[i][j] == 0) {
                cout << -1;
                return ;
            }
            if (result < box[i][j]) {
                result = box[i][j];
            }
        }
    }
    cout << result - 1;
}
int main(void) {

    int m;
    int n;
    int status;
    queue<pair<int, int>> q;
    vector<vector<int>> box;

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        vector<int> vec;
        for (int j = 0; j < m; j++) {
            cin >> status;
            vec.push_back(status);
            if (status == 1)
                q.emplace(i, j);
        }
        box.push_back(vec);
    }

    bfs(box, q);

    // 1. 1의 위치를 찾는다
    // 2. 1의 주변 상하좌우를 1로 바꿔준다 > -1인경우 바꾸지 않음
    // 3. 벡터의 어떤 요소가 0이 아니면 모두 전환 완료 > 모두 1로 채워진 상태를 어떻게 판단할까?
}