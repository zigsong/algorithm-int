//
// Created by songji on 2020/11/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999

using namespace std;

int V, adj[500][500];
// 각 정점에서 음주 운전 단속 소요 시간
int delay[500];
int W[500][500];

void solve() {
    // 모든 정점들을 예상 시간 별로 정렬
    vector<pair<int, int> > order;
    for (int i=0; i<V; ++i) {
        // pair는 first를 기준으로 sort하므로 인덱스가 아닌 소요시간을 pair의 key로 넣어 줌
        order.push_back(make_pair(delay[i], i));
    }
    sort(order.begin(), order.end());

    for (int i=0; i<V; ++i) {
        for (int j=0; j<V; ++j) {
            if (i == j) W[i][j] = 0;
            else W[i][j] = adj[i][j];
        }
    }

    int ret = INF;
    for (int k=0; k<V; ++k) {
        // k번째로 예상 시간이 적게 걸리는 정점 w까지를 지나서 얻을 수 있는 최단 거리
        int w = order[k].second;
        for (int i=0; i<V; ++i) {
            for (int j=0; j<V; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
                W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
            }
        }
    }
}