#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<vector<int>> dv;

int n;
int k;
int l;
int x = 0;

// right, down, left, up
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dir = 0;
deque<pair<int, int>> body;

vector<pair<int, char>> direction;
dv map;

bool is_valid(int nx, int ny) {

    for (auto & ptr : body) {
        if (ptr.first == nx && ptr.second == ny) {
            return false;
        }
    }
    return (nx >= 0 && ny >= 0 && nx < n && ny < n);
}

int main(void) {

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin >> n >> k;

    map.resize(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = 1; // 1 means there is apple;
    }

    cin >> l;

    for (int i = 0; i < l; i++) {
        int a;
        char b;
        cin >> a >> b;
        direction.emplace_back(a, b);
    }

    body.emplace_front(0, 0);
    int cnt = 0;
    while (1) {

        int nx = body.front().first;
        int ny = body.front().second;

        if (direction[cnt].first == x) {

            if (direction[cnt].second == 'D') { // turn right;
                dir = (dir + 1) % 4;
            } else if (direction[cnt].second == 'L') { // turn left;
                dir = (dir + 3) % 4; // mistake point
            }
            cnt++;
        }

        if (!is_valid(nx + dx[dir], ny + dy[dir])) {
            x++;
            break;
        }

        body.emplace_front(nx + dx[dir], ny + dy[dir]);
        if(map[nx + dx[dir]][ny + dy[dir]] != 1) { // if there is no apple
            body.pop_back();
        } else {
            map[nx + dx[dir]][ny + dy[dir]] = 0; // mistake point
        }
        x++;
    }

    cout << x;
    cout << (0 - 1) % 4;
//    cout << x << '\n';
//    cout << body.size() << '\n';
//
//    for(auto & ptr : map) {
//        for (auto & p : ptr) {
//            cout << p << ' ';
//        }
//        cout << '\n';
//    }
}