#include <algorithm>
#include "iostream"
#include "queue"
#include "vector"
using namespace std;
//#define INF numeric_limits<int>::max()
#define INF 3000001
int v, e, k;
vector<vector<pair<int, int>>> path;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
vector<int> d;

int main(void) {
    cin >> v >> e >> k;

    int start, end, weight;
    path.resize(v);
    for (int i = 0; i < e; i++) {
        cin >> start >> end >> weight;
        path[start - 1].emplace_back(make_pair(weight, end - 1));
    }
    d.resize(v, INF);
    d[k - 1] = 0;

    pq.emplace(0, k - 1);
    while (!pq.empty()) {
        int x = pq.top().first;
        int N = pq.top().second;
        pq.pop();

        for (int i = 0; i < path[N].size(); i++) {
            int next_W = path[N][i].first;
            int next_V = path[N][i].second;

            if (x + next_W < d[next_V]) { // 최소거리가 갱신되면 우선순위 큐에 삽입
                d[next_V] = x + next_W;
                pq.emplace(x + next_W, next_V);
            }
        }

    }
    for (int i = 0; i < v; i++) {
        if (d[i] == INF)
            cout << "INF" << '\n';
        else
            cout << d[i] << '\n';
    }
}

// 다익스트라 알고리즘
// 1. S = 방문한 노드의 집합, D[i] = 임의의 시작점으로부터 D[i]점까지 계산된 최단 거리, Q = 방문하지 않은 노드의 집합
// 2. 시작점의 D[i] = 0, 나머지 노드의 d[i]는 무한대로 설정
// 3. int infinity = std::numeric_limits<int>::max() 사용 / 문제를 고려하여 무한대로 간주할 수 있는 수 사용
// 4. D[i]가 최소인 i를 고름
// 5. i에서 방문가능한 노드 N에 대해 D[i] + P[i][N] < D[N] ? D[i] + P[i][N] : D[N]
// 6. i를 S에 넣어 방문처리
// 7. 미방문 상태인 노드 중 D[i]값이 가장 작은 노드 선택
// 8. 도착 노드가 방문 완료되거나 Q에 더 이상 노드가 없을 때 까지 5 ~ 7 반복
// 9. 도착 노드의 D[i]값이 시작점으로부터 최단 거리, INF라면 길이 끊긴 것을 의미