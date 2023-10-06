#include "iostream"
#include "vector"
#include "algorithm"
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
dice d;

bool movable(int dir) {
    if (dir == 1) {
        return (y + 1 < m);
    } else if (dir == 2) {
        return (y - 1 >= 0);
    } else if (dir == 3) {
        return (x - 1 >= 0);
    } else if (dir == 4) {
        return (x + 1 < n);
    } else
        return false;
}

void change_map() {
    if (map[x][y] == 0) {
        map[x][y] = d.bottom;
    } else {
        d.bottom = map[x][y];
        map[x][y] = 0;
    }
    cout << d.top << '\n';
}
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
//        cout << "now x, y :" << x << ", " << y << '\n';
        int dir;
        cin >> dir;
        int temp;
        if (dir == 1 && movable(dir)) { // east : left > bottom, bottom > right, right > top, top > left
            y += 1;
            temp = d.left;
            d.left = d.bottom;
            d.bottom = d.right;
            d.right = d.top;
            d.top = temp;
            change_map();
        } else if (dir == 2 && movable(dir)) { // west : reverse of east
            y -= 1;
            temp = d.left;
            d.left = d.top;
            d.top = d.right;
            d.right = d.bottom;
            d.bottom = temp;
            change_map();
        } else if (dir == 3 && movable(dir)) { // north : behind > bottom, bottom > front, front > top, top > behind
            x -= 1;
            temp = d.behind;
            d.behind = d.bottom;
            d.bottom = d.front;
            d.front = d.top;
            d.top = temp;
            change_map();
        } else if (dir == 4 && movable(dir)) { // south : reverse of north
            x += 1;
            temp = d.behind;
            d.behind = d.top;
            d.top = d.front;
            d.front = d.bottom;
            d.bottom = temp;
            change_map();
        }
    }
}