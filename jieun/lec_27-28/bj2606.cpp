//
// Created by songji on 2020/11/13.
//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > ntwk;
bool visited[101];
int answer = 0;

void dfs(int here) {
    visited[here] = true;

    for (int i=0; i<ntwk[here].size(); i++) {
        if (visited[ntwk[here][i]] == false) {
            dfs(ntwk[here][i]);
            answer++;
        }
    }

    return;
}

int main() {
    int num, pair;
    cin >> num >> pair;

    ntwk = vector<vector<int> >(num+1, vector<int>(num+1, 0));
//    ntwk.resize(num+1);

    int a, b;
    for (int i=0; i<pair; i++) {
        cin >> a >> b;
        ntwk[a].push_back(b);
        ntwk[b].push_back(a);
    }

    dfs(1);
    cout << answer << endl;

    return 0;
}