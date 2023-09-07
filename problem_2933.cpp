#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y, int r, int c) {
    return (x >= 0 && y >= 0 && x < r && y < c);
}

bool find_pair(vector <pair <int, int>> &arr, pair <int, int> p) {
    for (vector <pair<int, int>>::iterator ptr = arr.begin(); ptr != arr.end(); ptr++) {
        if (ptr->first == p.first && ptr->second == p.second)
            return true;
    }
        return false;
}

int get_diff(char **arr, vector<pair<int, int>> &vec, int r, int c) {
    int max = 0;
    bool stop = true;
    for (auto & ptr : vec) {
        if (ptr.first == r - 1)
            return 0;
    }
    while (stop) {
        for (auto & ptr : vec) {
            if (is_valid(ptr.first + max, ptr.second, r, c) && !find_pair(vec, make_pair(ptr.first + max, ptr.second))
             && (arr[ptr.first + max][ptr.second] == 'x' || ptr.first + max == r - 1))
            {
                stop = false;
                if (arr[ptr.first + max][ptr.second] == 'x')
                    max--;
            }
        }
        if (stop) {
            max++;
        }
    }
    return max;
}

bool find_cluster(char **arr, int row, int col, int r, int c, vector<pair<int, int>> &vec, vector<vector<bool>> &visited) {

    int nx;
    int ny;
    if (!is_valid(row, col, r, c) || arr[row][col] == '.' || visited[row][col]) {
        return false;
    }
    visited[row][col] = true;
    vec.push_back(make_pair(row, col));

    for (int i = 0; i < 4; i++) {
        nx = row + dx[i];
        ny = col + dy[i];
        if (is_valid(nx, ny, r, c)) {
            if (!visited[nx][ny] && arr[nx][ny] == 'x') {
                find_cluster(arr, nx, ny, r, c, vec, visited);
            }
        }
    }
    return true;
}

void combine_cluster(char **arr, int r, int c) {
    vector<pair<int,int>> result;
    vector<vector<bool>> visited(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j])
                continue;
            vector<pair<int, int>> cluster;
            if (find_cluster(arr, i, j, r, c, cluster, visited)) {
                int diff = get_diff(arr, cluster, r, c);
                if (diff) {
                    for (auto & ptr : cluster) {
                        arr[ptr.first][ptr.second] = '.';
                    }
                    for (auto & ptr : cluster) {
                        arr[ptr.first + diff][ptr.second] = 'x';
                    }
                    for (auto & ptr : visited) {
                        fill(ptr.begin(), ptr.end(), false);
                    }
                }
            }
        }
    }

}

int main(void) {
    int r = 0;
    int c = 0;
    int n = 0;
    int depth = 0;
    char letter;

    cin >> r >> c;

    char **map = new char *[r];

    for (int i = 0; i < r; i++)
        map[i] = new char[c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> letter;
            map[i][j] = letter;
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> depth;
        for (int j = 0; j < c; j++) {
            if (map[r - depth][j] == 'x' && i % 2 == 0) {
                //break x and combine cluster
                map[r - depth][j] = '.';
                combine_cluster(map, r, c);
                break;
            } else if (map[r - depth][c - j - 1] == 'x' && i % 2 == 1) {
                //break x and combine cluster
                map[r - depth][c - j - 1] = '.';
                combine_cluster(map, r, c);
                break;
            }
        }
    }

    for (int ia = 0; ia < r; ia++) {
        for (int ja = 0; ja < c; ja++) {
            cout << map[ia][ja];
        }
        cout << '\n';
    }
    return 0;
}