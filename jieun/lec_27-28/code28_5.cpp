//
// Created by songji on 2020/11/12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > adj;
vector<string> graph[26][26];

vector<int> indegree, outdegree;
void makeGraph(const vector<string>& words) {
    for (int i=0; i<26; ++i) {
        for (int j=0; j<26; ++j) {
            // removes all elements from the vector
            graph[i][j].clear();
        }
    }
    adj = vector<vector<int> >(26, vector<int>(26, 0));
    indegree = outdegree = vector<int>(26, 0);

    // 각 단어를 그래프에 추가
    for (int i=0; i<words.size(); ++i) {
        int a = words[i][0] - 'a'; // 단어의 첫 번째 알파벳
        int b = words[i][words[i].size()-1] - 'a'; // 단어의 마지막 알파벳
        graph[a][b].push_back(words[i]);
        adj[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
}

// 28-6
void getEulerCircuit(int here, vector<int>& circuit) {
    for (int there=0; there<adj.size(); ++there) {
        while(adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

vector<int> getEulerTrailOrCircuit() {
    vector<int> circuit;

    // 시작점이 존재하는 경우는 트레일
    for (int i=0; i<26; ++i) {
        if (outdegree[i] == indegree[i]+1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    // 아니면 서킷이니, 간선에 인접한 아무 정점에서나 시작
    for (int i=0; i<26; ++i) {
        if (outdegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    return circuit;
}

bool checkEuler() {
    // 예비 시작점과 끝점의 수
    int plus1 = 0, minus1 = 0;
    for (int i=0; i<26; ++i) {
        int delta = outdegree[i] - indegree[i];
        // 모든 정점의 차수는 -1, 1, 0 중 하나
        if (delta < -1 || 1 < delta) return false;
        if (delta == 1) plus1++;
        if (delta == -1) minus1--;
    }

    // 시작점과 끝점은 각 하나씩 있거나 하나도 없어야 한다
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve(const vector<int>& words) {
    makeGraph(words);
    if (!checkEuler()) return "IMPOSSIBLE";
    vector<int> circuit = getEulerTrailOrCircuit();
    // 모든 간선을 방문하지 못했으면 실패!
    if (circuit.size() != words.size + 1) return "IMPOSSIBLE";

    reverse(circuit.begin(), circuit.end());
    string ret;
    for (int i=1; i<circuit.size(); i++) {
        int a = circuit[i-1], b = circuit[i];
        if (ret.size()) ret += " ";
        ret += graph[a][b].back();
        graph[a][b].pop_back();
    }
    return ret;
}