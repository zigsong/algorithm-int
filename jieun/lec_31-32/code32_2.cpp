//
// Created by songji on 2020/12/15.
//
#include <vector>

using namespace std;

const int MAX_V = 100;

struct Edge {
    int target, capacity, flow;
    // 역방향 간선의 포인터
    Edge* reverse;
    int residualCapacity() const { return capacity - flow; }
    void push(int amt) {
        flow += amt;
        reverse->flow -= amt;
    }
};

vector<Edge*> adj[MAX_V];
void addEdge(int u, int v, int capacity) {
    Edge* uv = new Edge(), *vu = new Edge();
    uv->target = v;
    uv->capacity = capacity;
    uv->flow = 0;
    uv->reverse = vu;

    vu->target = u;
    vu->capacity = 0; // 용량 0인 유령 간선
    vu->flow = 0;
    vu->reverse = uv;

    adj[u].push_back(uv);
    adj[v].push_back(vu);
}