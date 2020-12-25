// 28.6 방향 그래프에서 오일러 서킷 혹은 트레일을 찾아내기

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

vector<vector<int> > adj;
// 유향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷 혹은 트레일을 계산한다.
void getEulerCircuit(int here, vector<int>& circuit) {
    for(int there = 0; there < adj.size(); ++there)
        while(adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    circuit.push_back(here);
}
// 현재 그래프의 오일러 트레일이나 서킷을 반환한다.
vector<int> getEulerCircuit() {
    vector<int> circuit;
    // 우선 트레일을 찾아본다: 시작점이 존재하는 경우
    for(int i = 0; i < 26; ++i)
        if(outdegree[i] == indegree[i]+1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    // 아니면 서킷이니, 간선에 인접한 아무 정점에서나 시작한다.
    for(int i - 0; i < 26; ++i)
        if(outdegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    // 모두 실패한 경우 빈 배열을 반환한다.
    return circuit;
}