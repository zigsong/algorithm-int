//
// Created by songji on 2020/11/26.
//
#include <vector>
#define MAX_V 9999
#define INF 99999

using namespace std;

int V;
int adj[MAX_V][MAX_V];
int C[MAX_V][MAX_V][MAX_V];

// 30-6
void allPairShortestPath1() {
    for (int i=0; i<V; ++i) {
        for (int j=0; j<V; ++j) {
            if (i != j) C[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
            else C[0][i][j] = 0;
        }
    }

    for (int k=1; k<V; ++k) {
        for (int i=0; i<V; ++i) {
            for (int j=0; j<V; ++j) {
                C[k][i][j] = min(C[k-1][i][j], C[k-1][i][k] = C[k-1][k][j]);
            }
        }
    }
}

// 30-7
void floyd() {
    for (int i=0; i<V; ++i) adj[i][i] = 0;
    for (int k=0; k<V; ++k) {
        for (int i=0; i<V; ++i) {
            for (int j=0; j<V; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

// 30-8
// u에서 v까지 가는 최단 경로가 경유하는 점 중 가장 번호가 큰 정점(가장 마지막에 갱신된 k), -1로 초기화
int via[MAX_V][MAX_V];
void floyd2() {
    for (int i=0; i<V; ++i) adj[i][i] = 0;
    memset(via, -1, sizeof(via));
    for (int k=0; k<V; ++k) {
        for (int i=0; i<V; ++i) {
            for (int j=0; j<V; ++j) {
                if (adj[i][j] > adj[i][k]+adj[k][j]) {
                    via[i][j] = k;
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }
}

// u에서 v로 가는 최단 경로를 계산해 path에 저장
void reconstruct(int u, int v, vector<int>& path) {
    // 경유하는 점 k가 아무것도 없으면
    if (via[u][v] == -1) {
        path.push_back(u);
        if (u != v) path.push_back(v);
    } else { // 경유점이 있다면
        int w = via[u][v];
        reconstruct(u, w, path);
        path.pop_back(); // w가 중복으로 들어가므로 삭제
        reconstruct(w, v, path);
    }
}