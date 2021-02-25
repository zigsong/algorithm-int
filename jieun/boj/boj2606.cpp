//
// Created by songji on 2021/02/25.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
vector<vector<int>> adj;
bool visited[MAX];
int total = 0;

void dfs(int x) {
    total++;
    visited[x] = true;
    for (int i=0; i<adj[x].size(); i++) {
        int next = adj[x][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    adj.resize(v + 1);

    for (int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    cout << total - 1 << "\n";
}