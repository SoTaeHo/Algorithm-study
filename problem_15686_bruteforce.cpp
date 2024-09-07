#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N, M, chicken = 0, result = 0;

int map[51][51];
vector<pair<int, int>> points;

bool is_member(pair<int, int> p, vector<pair<int, int>> selected) {
    for (auto &point: selected) {
        if (point.first == p.first && point.second == p.second) {
            return true;
        }
    }
    return false;
}

void check(vector<pair<int, int>> selected) {

    int temp = 0;
//    for(auto & i : selected) {
//        map[i.first][i.second] = 0;
//    }

    for (int i = 0; i < selected.size(); i++) {
        map[selected[i].first][selected[i].second] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 1) {
                int distance = 250;
                for (auto &point: points) {
                    if (is_member(point, selected))
                        continue;
                    int value = abs(i - point.first) + abs(j - point.second);
//                    cout << value << endl;
                    if (distance > value)
                        distance = value;
                }
                temp += distance;
            }
        }
    }
    if (result == 0 || result > temp) {
        result = temp;
    }
//    cout << "result : " << result << endl;
    for (int i = 0; i < selected.size(); i++) {
        map[selected[i].first][selected[i].second] = 2;
    }
}

void find(vector<pair<int, int>> arr, int index) {
    if (arr.size() == chicken - M) {
//        cout << "if";
        check(arr);
        return;
    }

    for (int i = index; i < points.size(); i++) {
        arr.emplace_back(points[i]);
//        cout << "loop";
        find(arr, i + 1);
        arr.pop_back();
    }
}


int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                chicken++;
                points.emplace_back(i, j);
            }
        }
    }
//    cout << chicken << endl;
//    cout << points.size() << endl;
    vector<pair<int, int>> selected;
    find(selected, 0);
    cout << result;
}