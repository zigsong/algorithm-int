//
// Created by songji on 2020/12/15.
//
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkFlow(int source, int sink) {
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while (true) {
        vector<int> parent(MAX_V, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while (!q.empty() && parent[sink] == 1) {
            int here = q.front();
            q.pop();
            for (int there=0; there<V; ++there) {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        // 증가 경록 없으면 종료
        if (parent[sink] == -1) break;
        // 증가 경로를 통해 유량을 얼마나 보낼지 결정
        int amount = INF;
        for (int p=sink; p!=source; p=parent[p]) {
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        }
        for (int p=sink; p!=source; p=parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}