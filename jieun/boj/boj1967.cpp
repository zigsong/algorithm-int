//
// Created by songji on 2021/02/25.
//
// 트리의 지름: 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이
// dfs 2번 돌기
// 지름의 양 끝을 연결하는 두 노드는 모두 리프 노드

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 10001;
vector<pair<int, int>> map[MAX];
bool visited[MAX];
int endNode;
int ans = 0;

void dfs(int v, int dist) {
    if (visited[v]) return;
    visited[v] = true;

    if (ans < dist) {
        ans = dist;
        endNode = v;
    }

    for (int i=0; i<map[v].size(); i++) {
        dfs(map[v][i].first, dist + map[v][i].second);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        map[p].push_back(make_pair(c, w));
        map[c].push_back(make_pair(p, w));
    }

    dfs(1, 0); // 여기서 계산한 ans는 의미가 없음. 첫 번째 endNode를 구하기 위한 작업
    ans = 0;

    memset(visited, false, sizeof(visited));

    dfs(endNode, 0);
    cout << ans << "\n";
}