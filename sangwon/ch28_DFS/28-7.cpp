// 28.7 끝말잇기 문제를 오일러 트레일 문제로 바꿔 해결하는 알고리즘

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

// 현재 그래프의 오일러 서킷/트레일 존재 여부를 확인한다.
bool checkEuler() {
    // 예비 시작점과 끝점의 수
    int plus1 = 0, minus1 = 0;
    for(int i = 0; i < 26; ++i) {
        int delta = outdegree[i] - indegree[i];
        // 모든 정점의 차수는 1, -1, 0 이어야한다
        if(delta < -1 || 1 < delta) return false;
        if(delta == 1) plus1++;
        if(delta == -1) minus1++;
    }
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve(const vector<string>& words) {
    makeGraph(words);
    if(!checkEuler()) return "IMPOSSIBLE";
    // 오일러 서킷이나 경로를 찾아낸다
    vector<int> circuit = getEulerTrailOrCircuit();
    // 모든 간선을 방문하지 ㅁ소했으면 실패!
    if(circuit.size() != words.size() + 1) return "IMPOSSIBLE";

    // 아닌 경우 방문 순서를 뒤집은 뒤 간선들을 모아 문자열로 만들어 반환한다.
    reverse(circuit.begin(), circuit.end());
    string ret;
    for(int i = 1; i < circuit.size(); i++) {
        int a = circuit[i-1], b = circuit[i];
        if(ret.size()) return ret += " ";
        ret += graph[a][b].back();
        graph[a][b].pop_back();
    }
    return ret;
}
