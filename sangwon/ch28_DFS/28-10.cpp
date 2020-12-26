// 28.10 타잔의 강결합 컴포넌트 분리 알고리즘의 구현

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