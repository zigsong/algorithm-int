//
// Created by songji on 2021/01/21.
//

// https://www.weeklyps.com/entry/트리의-지름
// https://lmcoa15.tistory.com/56
// 모르겠어~
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 50001;
int n;
int D[MAX];
bool visited[MAX];
vector<pair<int, int>> graph[MAX];

int res = 0;
int endNode = 0;

void dfs(int curr, int dist) {
    visited[curr] = true;

    if (dist > res) {
        res = dist;
        endNode = curr;
    }

    for (int i=0; i<graph[curr].size(); i++) {
        int nextNode = graph[curr][i].first;
        int nextDist = graph[curr][i].second;
        if (!visited[nextNode]) dfs(nextNode, nextDist);
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int from, to, len;
        cin >> from >> to >> len;
        graph[from].push_back(make_pair(to, len));
        graph[to].push_back(make_pair(from, len));
    }

    // 가장 멀리 있는 정점(endPoint) 구하기
    dfs(1,0);

    res = 0;
    memset(visited, false, sizeof(visited));
    dfs(endNode, 0);


    for (int i=0; i<n; i++) {
        cout << D[i] << "\n";
    }
}