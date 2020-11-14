//
// Created by songji on 2020/11/12.
//

#include <vector>

using namespace std;

vector<vector<int> > adj;

void getEulerCircuit(int here, vector<int>& circuit) {
    for (int there=0; there<adj[here].size(); ++there) {
        while(adj[here][there] > 0) {
            adj[here][there]--; // 양쪽 간선을 모두 지움
            adj[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}
