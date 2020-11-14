//
// Created by songji on 2020/11/12.
//

#include <vector>
#include <algorithm>

using namespace std;

// 간선 (i,j)는 알파벳 i가 j보다 앞에 와야 함을 나타냄
vector<vector<int> > adj;

void makeGraph(const vector<string>& words) {
    adj = vector<vector<int> >(26, vector<int>(26, 0));
    for (int j=1; j<words.size(); ++j) {
        int i = j-1, len = min(words[i].size(), words[j].size());
        // words[i]가 words[j] 앞에 오는 이유
        for (int k=0; k<len; ++k) {
            int a = words[i][k] - 'a';
            int b = words[j][k] - 'a';
            adj[a][b] = 1;
            break;
        }
    }
}

vector<int> seen, order;
void dfs(int here) {
    seen[here] = 1;
    for (int there=0; there<adj.size(); ++there) {
        if (adj[here][there] && !seen[there])
            dfs(there);
    }
    order.push_back(here);
}

vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();
    for (int i=0; i<m; ++i) if (!seen[i]) dfs(i);
    reverse(order.begin(), order.end());

    // 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다
    for (int i=0; i<m; ++i) {
        for (int j=i+1; j<m; ++j) {
            if (adj[order[j]][order[i]])
                return vector<int>();
        }
    }
    return order;
}