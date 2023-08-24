#include "iostream"

using namespace std;

int main(void) {
    int r = 0;
    int c = 0;
    int n = 0;
    int depth = 0;
    char letter;

    cin >> r >> c;

    int **map = new int*[r];

    for (int i = 0; i < c; i++)
        map[i] = new int[c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> letter;
            map[i][j] = letter;
        }
    }
    // combine cluster
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> depth;
        for (int j = 0; j < c; j++) {
            if (map[depth][j] == 'x' && j % 2 == 0) {
                //break x and combine cluster
                map[depth][j] = '.';

            }
            else if (map[depth][c - j] == 'x' && j % 2 == 1) {
                //break x and combine cluster
                map[depth][j] = '.';

            }
        }
    }

    return 0;
}