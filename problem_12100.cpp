#include "iostream"
#include "vector"

using namespace std;

int main(void) {
    int n;
    vector<vector<int>> map;

    cin >> n;

    map.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // 총 4^5 : 512 가지의 경우의 수
    // 합친 후 제일 크다고 최대 5번 움직였을 때 제일 큰 경우는 아님
    // 움직인 방향을 저장할 수 있는 방법이 있을까?
    // 어떤 상황에서 백트래킹을 걸 수 있을까 : 타일이 1개 / 타일이 n개인데 모두 수가 다를 때 / 움직여도 합칠 방법이 없을 때 => 합칠 수 없는 상황
    // 상 : 00 / 하 : 01 / 좌 : 10 / 우 : 11 > 총 10비트로 방향 확정 가능
    // ex) 00 00 00 00 00 : 상 상 상 상 상 / 00 01 00 01 00 : 상 하 상 하 상
}