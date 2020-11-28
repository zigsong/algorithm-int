#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cassert>
#include<numeric>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<deque>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
typedef long long ll;

const int MAX_V = 100;
const int INF = 987654321;

// 정점의 개수
int V; 
// 그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int,int> > adj[MAX_V];
// 경로 존재 여부
bool reachable[MAX_V][MAX_V];
// src에서 target으로 가는 최단 거리 계산
// 가중치가 음의 무한대인 경로가 있으면 -INF를 반환
int bellman2(int src, int target) {
    // 시작점을 제외한 모든 정점까리의 최단거리 상한 INF
    vector<int> upper(V, INF);
    upper[src] = 0;
    // V-1번 순회
    for(int iter = 0; iter < V-1; ++iter)
        for(int here = 0; here < V; ++here)
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                // (here, there)간선을 따라 완화 시도
                upper[there] = min (upper[there], upper[here]+cost);
            }
    // 음수 사이클 존재 여부 확인
    for(int here = 0; here< V; ++here)
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int cost = adj[here][i].second;
            // 완화가 성공한다면 here는 음수 사이클에 들어있다
            if (upper[here] + cost < upper[there])
            // 이 음수 사이클을 포함하는 경로가 있는가? 
            if(reachable[src][here] && reachable[here][target]) return -INF;
        }
     return upper[target];
}