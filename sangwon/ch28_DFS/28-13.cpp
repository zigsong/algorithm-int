// 28.13 2-SAT 문제 해결하기

#include <vector>
#include <stack>
using namespace std;

vector<vector<int> > adj;

vector<int> sccId;
vector<int> discovered;
stack<int> st;
int sccCounter, vertexCounter;

int scc(int here) {
    int ret = discovered[here] = vertexCounter++;
    st.push(here);
    for(int i = 0; i <adj[here].size(); ++i) {
        int there = adj[here][i];
        if(discovered[there] == -1)
            ret = min(ret, scc(there));
        else if(sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }
    if(ret == discovered[here]) {
        while(true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if(t == here) break;
        }
        ++sccCounter;
    }
    return ret;
}

vector<int> tarjanSCC() {
    sccId = discovered = vector<int>(adj.size(), -1);
    sccCounter = vertexCounter = 0;
    for(int i = 0; i < adj.size(); i++) if(discovered[i] == -1) scc(i);
    return sccId;
}

vector<int> solve2SAT() {
    int n = adj.size() / 2;
    vector<int> label = tarjanSCC();
    for(int i = 0; i < 2 * n; i += 2)
        if(label[i] == label[i+1])
            return vector<int>();
    
    vector<int> value(2 * n, -1);

    vector<pair<int, int> > order;
    for(int i = 0; i < 2 * n; i++) {
        int vertex = order[i].second;
        int variable = vertex / 2, isTrue = vertex % 2 == 0;
        if(value[variable] != -1) continue;

        value[variable] = !isTrue;
    }
    return value;
}