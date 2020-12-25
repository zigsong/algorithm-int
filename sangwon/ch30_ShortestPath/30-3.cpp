// 30.3 다익스트라 알고리즘을 이용해 철인 N종 경기 문제를 해결하기

#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

// 정점의 개수
int V;

vector<pair<int, int> > adj[410];
const int START = 401;

int vertex(int delta) {
    return delta + 200;
}

int solve(const vector<int>& a, const vector<int>& b) {
    V = 402;
    for(int i = 0; i < V; i++) adj[i].clear();
    for(int i = 0; i < a.size(); i++) {
        int delta = a[i] - b[i];
        adj[START].push_back(make_pair(vertex(delta), a[i]));
    }
    for(int delta = -200; delta <= 200; ++delta) {
        for(int i = 0; i < a.size(); ++i) {
            int next = delta + a[i] - b[i];
            if(abs(next) > 200) continue;
            adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
        }
    }
    vector<int> shortest = dijkstra(START);
    int ret = shortest[vertex(0)];
    if(ret == INF) return -1;
    return ret;
}