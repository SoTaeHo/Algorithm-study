#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<pair<int, int>> temp;
vector<vector<bool>> visited;

bool is_valid(int x, int y, int r, int c) {
    return (x >= 0 && y >= 0 && x < r && y < c);
}

bool find_pair(vector <pair <int, int>> arr, pair <int, int> p) {
    for (vector <pair<int, int>>::iterator ptr = arr.begin(); ptr != arr.end(); ptr++) {
        if (ptr->first == p.first && ptr->second == p.second)
            return true;
    }
        return false;
}

int get_diff(char **arr, int r, int c) {
    int max = 0;
    bool stop = true;

    while (stop) {
        for (vector<pair<int, int>>::iterator ptr = temp.begin(); ptr != temp.end(); ptr++) {
            if (is_valid(ptr->first + max, ptr->second, r, c) && !find_pair(temp, make_pair(ptr->first + max, ptr->second))
             && (arr[ptr->first + max][ptr->second] == 'x' || ptr->first + max == r - 1))
            {
                stop = false;
                if (arr[ptr->first + max][ptr->second] == 'x')
                    max--;
            }
        }
        if (stop) {
            max++;
        }
    }
    return max;
}

bool find_cluster(char **arr, int row, int col, int r, int c) {

    int nx;
    int ny;
    if (!is_valid(row, col, r, c) || arr[row][col] == '.' || visited[row][col]) {
        return false;
    }
    visited[row][col] = true;
    temp.push_back(make_pair(row, col));

    for (int i = 0; i < 4; i++) {
        nx = row + dx[i];
        ny = col + dy[i];
        if (is_valid(nx, ny, r, c)) {
            if (!visited[nx][ny] && arr[nx][ny] == 'x') {
                find_cluster(arr, nx, ny, r, c);
            }
        }
    }
    return true;
}

void combine_cluster(char **arr, int r, int c) {


    for (int i = 0; i < r; i++) {
        vector<bool> vec;
        visited.push_back(vec);
        for (int j = 0; j < c; j++) {
            visited[i].push_back(false);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
                if (!visited[i][j] && arr[i][j] == 'x' && find_cluster(arr, i, j, r, c)) {
                    bool bottom = false;
                    cout << "pass";
                    for (vector<pair<int, int>>::iterator ptr = temp.begin(); ptr != temp.end(); ptr++) {
                        if (ptr->first == r - 1) {
                            temp = {};
                            bottom = true;
                        }
                    }
                    if (bottom)
                        continue;
                    int diff = get_diff(arr, r, c);
//                  for (auto & ptr : temp) {
                    if (diff) {
                        for (vector<pair<int, int>>::iterator ptr = temp.begin(); ptr != temp.end(); ptr++) {
                            arr[ptr->first][ptr->second] = '.';
                        }
                        for (vector<pair<int, int>>::iterator ptr = temp.begin(); ptr != temp.end(); ptr++) {
                            arr[ptr->first + diff][ptr->second] = 'x';
                        }
                    }
                    for (vector<vector<bool>>::iterator ptr = visited.begin(); ptr != visited.end(); ptr++) {
                        fill(ptr->begin(), ptr->end(), false);
                        temp = {};
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

    // combine cluster
    combine_cluster(map, r, c);

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