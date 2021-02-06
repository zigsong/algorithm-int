//
// Created by songji on 2021/01/21.
//

// 그래프(dfs)를 만들지 않고 문제 해결
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 1000000;
int n;
vector<int> friends[MAX];
int dp[MAX][2]; // 노드, 얼리어답터 여부

int getDP(int curr, int prev, int flag) {
    int &cache = dp[curr][flag];
    if (cache != -1) return cache;
    int cnt = 0;
    if (flag == 0) {
        for (int i=0; i<friends[curr].size(); i++) {
            int next = friends[curr][i];
            if (next == prev) continue; // 중복 거르기
            cnt += getDP(next, curr, 1);
        }
        return cache = cnt;
    }
    else {
        for (int i=0; i<friends[curr].size(); i++) {
            int next = friends[curr][i];
            if (next == prev) continue;
            cnt += min(getDP(next, curr, 0), getDP(next, curr, 1));
        }
        return cache = cnt + 1;
    }
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
    // 루트가 얼리어답터일 때와, 루트가 얼리어답터가 아닐 때 중 최소값
    cout << min(getDP(1, 0, 1), getDP(1, 0, 0));
}