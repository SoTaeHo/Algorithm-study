#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

typedef vector< vector<int> > dv;

vector<int> value(512, 0);

int dx[] = {-1,1, 0, 0};
int dy[] = {0, 0, -1,1};

dv move_tile(int direction, dv &map) {
    // up : ji/j++ down : ji/j-- left : ij/j-- right : ij/j++
    pair<int, int> p = make_pair(0, 0);
    for(int i = 0; i < map.size(); i++) {
        int val = 0;
        vector<int> temp;
        for(int j = 0; j < map.size(); j++) {
            if (map[j][i] != val && map[j][i] != 0) {
                val = map[j][i];
                p.first = j;
                p.second = i;
                map[j][i] = 0;
                temp.push_back(val);
            } else if (map[j][i] == val && map[j][i] != 0) {
                temp[temp.size() - 1] *= 2;
                map[j][i] = 0;
                val = 0;
            }
        }
        for (int j = 0; j < temp.size(); j++) {
            map[j][i] = temp[j];
        }
    }

    return map;
}

int shift_value(int order, dv map) {
    int max_value = 0;

    for(int i = 0; i < 5; i++) {
        int shifted_value = (order >> (i * 2)) & 0b11;
        map = move_tile(shifted_value, map);
    }
    for (auto & ptr : map) {
        for (auto & p : ptr) {
            if (max_value < p)
                max_value = p;
        }
    }
    return max_value;
}
int main(void) {
    int n;
    unsigned int order = 0;
    dv map;

    cin >> n;

    map.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    while (order != 512) {
        value[order] = shift_value(order, map);
        order++;
    }
    cout << *max_element(value.begin(), value.end());
    // 총 4^5 : 512 가지의 경우의 수
    // 합친 후 제일 크다고 최대 5번 움직였을 때 제일 큰 경우는 아님
    // 움직인 방향을 저장할 수 있는 방법이 있을까?
    // 어떤 상황에서 백트래킹을 걸 수 있을까 : 타일이 1개 / 타일이 n개인데 모두 수가 다를 때 / 움직여도 합칠 방법이 없을 때 => 합칠 수 없는 상황
    // 상 : 00 / 하 : 01 / 좌 : 10 / 우 : 11 > 총 10비트로 방향 확정 가능
    // ex) 00 00 00 00 00 : 상 상 상 상 상 / 00 01 00 01 00 : 상 하 상 하 상
}