#include "iostream"
#include "vector"

using namespace std;

int n, m;
vector<vector<int>> map;

int main(void) {
    cin >> n >> m;
    map.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

}