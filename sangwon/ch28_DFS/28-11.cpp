// 28.11 감시 카메라 문제를 해결하는 알고리즘의 구현

#include <map>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_V = 1000000;

int V;
vector<int> adj[MAX_V];
vector<bool> visited;
const int UNMATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int installed;
int djs(int here) {
    visited[here] = true;
    int children[3] = {0, 0, 0};
    for(int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        if(!visited[there])
            ++children[dfs(there)];
    }
    if(children[UNMATCHED]) {
        ++installed;
        return INSTALLED;
    }

    if(children[INSTALLED])
        return WATCHED;
    return UNMATCHED;
}

int installCamera() {
    installed = 0;
    visited = vector<bool>(V, false);
    for(int u = 0; u < V; ++u) 
        if(!visited[u] && dfs(u) == UNMATCHED)
            ++installed;
    return installed;
}