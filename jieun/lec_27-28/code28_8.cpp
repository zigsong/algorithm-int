//
// Created by songji on 2020/11/12.
//

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > adj;

// discovered[i] = i번 정점의 발견 순서
// finished[i] = dfs(i)가 종료했으면 1, 아니면 0
vector<int> discovered, finished;
// 지금까지 발견한 정점의 수
int counter;

void dfs2(int here) {
    discovered[here] = counter++;
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];
        cout << "(" << here << "," << there << ") is a ";
        // 아직 there를 방문하지 않았다면
        if (discovered[there] == -1) {
            cout << "tree edge" << endl;
            dfs2[there];
        }
        // there가 here보다 늦게 발견됐다면
        else if (discovered[here] < discovered[there]) cout << "forward edge" << endl;
        // 만약 dfs2(there)가 아직 종료하지 않았다면
        else if (finished[there] = 0) cout << "back edge" << endl;
        // 이외는 모두 교차 간선
        else cout << "cross edge" << endl;
    }
    finished[here] = 1;
}

