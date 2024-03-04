#include "iostream"
#include "vector"

using namespace std;
typedef vector<vector<int>> td;

int n, m;
td map;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n, m;
    map.resize(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }


}