#include <iostream>
#include <vector>

using namespace std;

int N, X, Y, D, G, result = 0;
bool map[101][101]; // map[y][x]

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void draw(int x, int y, int d, int g) {
    map[y][x] = true;
    int nx = x + dx[d];
    int ny = y + dy[d];

    map[ny][nx] = true;
    vector<int> arr;
    arr.push_back(d);
    for (int i = 0; i < g; i++) {
        int size = arr.size();
        for (int j = size - 1; j >= 0; j--) {
            arr.push_back((arr[j] + 1) % 4);
        }
//        cout << endl;
//        for (int k: arr) {
//            cout << k << " ";
//        }
//        cout << endl;
    }

    for (int j = 1; j < arr.size(); j++) {
        map[ny + dy[arr[j]]][nx + dx[arr[j]]] = true;
        nx = nx + dx[arr[j]];
        ny = ny + dy[arr[j]];
    }
//    for(int i : arr) {
//        cout << i << " ";
//    }
//    cout << endl;
}

void check() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] && map[i + 1][j + 1] && map[i][j + 1] && map[i + 1][j])
                result++;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X >> Y >> D >> G;
        draw(X, Y, D, G);
//        for (int i = 0; i < 11; i++) {
//            for (int j = 0; j < 11; j++) {
//                cout << map[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }
    check();
    cout << result << endl;

//    for (int i = 0; i < 11; i++) {
//        for (int j = 0; j < 11; j++) {
//            cout << map[i][j] << " ";
//        }
//        cout << endl;
//    }
}

//0. 0
//1. 0 1
//2. 0 1 2 1
//3. 0 1 2 1 2 3 2 1
//4. 0 1 2 1 2 3 2 1 / 2 3 0 3 2 3 2 1