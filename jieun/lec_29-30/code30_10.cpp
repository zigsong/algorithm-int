//
// Created by songji on 2020/11/26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, adj[200][200];
// 간선 (a, b)를 추가했을 때 그래프의 최단 거리 배열 adj를 적절히 갱신
// 간선이 무의미할 경우 false를 반환
bool update(int a, int b, int c) {
    if (adj[a][b] <= c) return false;
    for (int i=0; i<V; ++i) {
        for (int j=0; j<V; ++j) {
            // 모든 정점을 돌면서, a-b를 추가함으로써 이 간선을 이용할 수 있는 경우와 아닌 경우가 있음
            // a-b를 이용하지 않는 경우에는 그냥 adj[i][j] 값을 이용
            adj[i][j] = min(adj[i][j], min(adj[i][a] + c + adj[b][j], adj[i][b] + c + adj[a][j]));
        }
    }
    return true;
}