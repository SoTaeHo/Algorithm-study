#include "iostream"
#include "vector"

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<pair<int, int>> temp;

bool is_valid(int x, int y, int r, int c) {
    return (x >= 0 && y >= 0 && x < r && y < c);
}

bool find_cluster(char **arr, int row, int col, int r, int c) {

    int nx;
    int ny;

    if (!is_valid(row, col, r, c) || arr[row][col] == '.' || row == r - 1) {
        temp = {};
        cout << "temp clear\n";
        return false;
    }

    arr[row][col] = '.';
    pair<int, int> a = make_pair(row, col);
    cout << a.first << " " << a.second << '\n';
    temp.push_back(make_pair(row, col));

    for (int i = 0; i < 4; i++) {
        nx = row + dx[i];
        ny = col + dy[i];
        if (is_valid(nx, ny, r, c)) {
            if (arr[nx][ny] == 'x')
                find_cluster(arr, nx, ny, r, c);
        }
    }
    arr[row][col] = 'x';
    return true;
}

void combine_cluster(char **arr, int r, int c) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 'x')
                if (find_cluster(arr, i, j, r, c)) {
                    int max = 1;
                    for (vector<pair<int, int>>::iterator ptr = temp.begin(); ptr != temp.end(); ptr++) {
                        if (arr[ptr->first + max][ptr->second] == 'x' || )
                            break;
                        max++;
                    }
//                  for (auto & ptr : temp) {
                    for (vector<pair<int, int>>::iterator ptr = temp.begin(); ptr != temp.end(); ptr++) {
                        arr[ptr->first][ptr->second] = '.';
                    }
                    for (vector<pair<int, int>>::iterator ptr = temp.begin(); ptr != temp.end(); ptr++) {
                        arr[ptr->first][ptr->second] = 'x';
                    }
                    temp = {};
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

    for (int i = 0; i < c; i++)
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
            if (map[depth - 1][j] == 'x' && j % 2 == 0) {
                //break x and combine cluster
                map[depth - 1][j] = '.';
                combine_cluster(map, r, c);
                break;
            } else if (map[depth - 1][c - j] == 'x' && j % 2 == 1) {
                //break x and combine cluster
                map[depth - 1][c - j] = '.';
                combine_cluster(map, r, c);
                break;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}