#include "iostream"
#include "vector"
using namespace std;

typedef vector<vector<int>> dv;
struct dice {
    int front = 0;
    int behind = 0;
    int left = 0;
    int bottom = 0;
    int right = 0;
    int top = 0;
};
int n, m, x, y, k;
dv map;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x >> y >> k;

    map.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> k;
        if (k == 1) { // east : left > bottom, bottom > right, right > top, top > left

        } else if (k == 2) { // west : reverse of east

        } else if (k == 3) { // north : behind > bottom, bottom > front, front > top, top > behind

        } else if (k == 4) { // south : reverse of north

        }
    }
}