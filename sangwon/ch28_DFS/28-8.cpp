// 28.8 간선을 구분하는 깊이 우선 탐색의 구현

#include <map>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 그래프의 인접 리스트 표현
vector<vector<int> > adj;
// discovered[i]=i번 정점의 발견 순서
// finished[i] = dfs(i)가 종료했으면 1, 아니면 0
vector<int> discovered, finished;
// 지금까지 발견한 정점의 수
int counter;

void dfs2(int here) {
    discovered[here] = counter++;
    // 모든 인접 정점을 순회하면서
    for(int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        cout << "(" << here << "," << there << ") is a ";
        // 아직 방문한 적 없다면 방문한다.
        if(discovered[there] == -1) {
            cout << "tree edge" << endl;
            dfs2(there);
        }
        // 만약 there 가 here 보다 늦게 발견되었으면 there 는  here 의 후손이다.
        else if(discovered[here] < discovered[there])
            cout << "forward edge" << endl;
        else if(finished[there] == 0) 
            cout << "back edge" << endl;
        else 
            cout << "cross edge" << endl;
    }
    finished[here] = 1;
}
