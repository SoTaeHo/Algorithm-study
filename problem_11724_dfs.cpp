#include <iostream>
#include <vector>

using namespace std;

int N, M, result = 0;
vector<bool> visited;
vector<vector<int>> map;

void dfs(int cnt) {

    if(visited[cnt]) {
        return;
    }

    visited[cnt] = true;

    for(int i : map[cnt]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> N >> M;
    map.resize(N + 1);
    visited.resize(N + 1, false);
    int a, b;
    for(int i = 1; i <= M; i++) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            dfs(i);
            result++;
        }
    }

    cout << result;
}