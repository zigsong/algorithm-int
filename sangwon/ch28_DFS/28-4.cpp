// 28.4 깊이 우선 탐색을 이용한 오일러 서킷 찾기
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

// 그래프의 인접 행렬 표현. adj[i][j] = i 와 j 사이의 간선 수
vector<vector<int> > adj;
// 무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 계산한다.
// 결과로 얻어지는 circuit 을 뒤집으면 오일러 서킷이 된다.
void getEulerCircuit(int here, vector<int>& circuit) {
    for(int there = 0; there < adj[here].size(); ++there)
        while(adj[here][there] > 0) [
            adj[here][there]--;
            adj[there][here]--;
            getEulerCircuit(there, circuit);
    circuit.push_back(here);
}