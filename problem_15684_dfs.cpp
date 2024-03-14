#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> map;
//vector<vector<bool>> link;
bool link[11][30];

int N, M, H, result = 99999999;
int min(int a, int b) {if (a < b) return a; return b;}

bool check() {

    for (int i = 1; i <= N; i++) {
        int line = i;
        for (int j = 1; j <= H; j++) {
            if (link[line][j]) {
                line += 1;
            }
            else if (link[line - 1][j]) {
                line -= 1;
            }
        }
        if (line != i) {
            return false;
        }
    }
    return true;
}

void loop(int idx, int cnt) {
    if (cnt >= 4) {
        return;
    }

    if(check()) {
        result = min(result, cnt);
        return;
    }

    // H * N - 1의 2차원 벡터
    for (int i = idx; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (link[j][i]) continue;
            if (link[j - 1][i]) continue;
            if (link[j + 1][i]) continue;

            link[j][i] = true;
            loop(i, cnt + 1);
            link[j][i] = false;
        }
    }
}

int main() {
    cin >> N >> M >> H;

//    link.resize(H, vector<bool>(N - 1, false));
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        link[b][a] = true;
    }

    for(int i = 0; i < 4; i++) {
        loop(1, i);
    }
//    loop(1, 0);

    if (result == 99999999) cout << -1;
    else cout << result;
}