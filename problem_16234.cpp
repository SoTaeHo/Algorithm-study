#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, R;
int map[51][51];
bool selected[51][51];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int sum = 0, country = 0;
vector<pair<int, int>> point;

bool check(int i, int j) {
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
            continue;
        }
        if (abs(map[nx][ny] - map[i][j]) >= L && abs(map[nx][ny] - map[i][j]) <= R) {
//            cout << abs(map[nx][ny] - map[i][j]) << " ";
            return true;
        }
    }
    return false;
}

void dfs(int r, int k) {
    if (r < 0 || r >= N || k < 0 || k >= N)
        return;

    if (selected[r][k])
        return;

    selected[r][k] = true;
    point.emplace_back(r, k);
    sum += map[r][k];
    country++;

    for (int i = 0; i < 4; i++) {
        int nx = r + dx[i];
        int ny = k + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
            continue;
        }
        if (abs(map[nx][ny] - map[r][k]) >= L && abs(map[nx][ny] - map[r][k]) <= R) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int day = 0;
    bool condition = true;
    bool day_change = false;
    // 1. 인구차이가 L이상 R이하면 국경을 연다
    // 2. 연합이 된 칸을 조사 후 인구 수 / 칸 수 된 값을 설정
    while (condition) {
        condition = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (selected[i][j])
                    continue;
                // bfs
                dfs(i, j);

                for (auto &ptr: point) {
                    map[ptr.first][ptr.second] = sum / country;
                }
                if (point.size() > 1 && !day_change) {
                    day++;
                    day_change = true;
                }

                sum = 0;
                country = 0;
                point.clear();
                point.shrink_to_fit();
            }
        }

        // 선택된 맵 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                selected[i][j] = false;
            }
        }

        //
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (check(i, j)) {
                    condition = true;
                }
            }
        }
        // 3. 모두 완료했으면 날짜증가
        day_change = false;
//        day++;
        // 4. 반복
    }

    cout << day;
}