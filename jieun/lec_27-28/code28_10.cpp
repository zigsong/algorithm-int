//
// Created by songji on 2020/11/12.
//

#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > adj;

// 각 정점의 컴포넌트 번호. 컴포넌트 번호는 0부터 시작하며,
// 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
vector<int> sccId;
// 각 정점의 발견 순서
vector<int> discovered;
// 정점의 번호를 담는 스택
stack<int> st;
int sccCounter, vertexCounter;

int scc(int here) {
    int ret = discovered[here] = vertexCounter++;
    st.push(here);
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];
        if (discovered[there] == -1) ret = min(ret, scc(there));
        else if (sccId[there] == -1) ret = min(ret, discovered[there]);
    }
    if (ret == discovered[here]) {
        while(true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if (t == here) break;
        }
        ++sccCounter;
    }
    return ret;
}

vector<int> tarjanSCC() {
    sccId = discovered = vector<int>(adj.size(), -1);
    sccCounter = vertexCounter = 0;
    for (int i=0; i<adj.size(); i++) if (discovered[i] == -1) scc(i);
    return sccId;
}