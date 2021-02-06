//
// Created by songji on 2021/01/21.
//

// dp, 점화식
// 필요한 얼리어답터의 최소 수 구하기
// 1. 본인이 얼리어답터라면 자식은 얼리어답터여도, 아니어도 괜찮다.
// 2. 본인이 얼리어답터가 아니라면 자식은 무조건 얼리어답터

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
int n; // n <= 1,000,000
vector<int> friends[MAX];
vector<int> graph[MAX];
int dp[MAX][2]; // 노드, 얼리어답터 여부
bool visited[MAX];

// 트리로 그래프 만들기
void dfs(int idx) {
    visited[idx] = true;
    for (int i=0; i<friends[idx].size(); i++) {
        int next = friends[idx][i];
        if (!visited[next]) {
            graph[idx].push_back(next);
            dfs(next);
        }
    }
}

int getEA(int curr, int flag) {
    if (dp[curr][flag] != 0) return dp[curr][flag];
    // 자식이 없다면 (curr가 리프 노드)
    // 아래 코드를 넣으면 메모리 조금 감소
    if (graph[curr].size() == 0) return dp[curr][flag] = flag;

    // 본인이 얼리어답터라면
    if(flag) {
        int cnt = 0;
        // 자식은 얼리어답터든 아니든 상관 없음
        for (int i=0; i<graph[curr].size(); i++) {
            int child = graph[curr][i];
            cnt += min(getEA(child, 1), getEA(child, 0));
        }
        return dp[curr][flag] = cnt + 1; // 자기 자신 포함
    }
    // 본인이 얼리어답터가 아니라면
    else {
        int cnt = 0;
        // 자식들이 얼리어답터여야 함
        for (int i=0; i<graph[curr].size(); i++) {
            int child = graph[curr][i];
            cnt += getEA(child, 1);
        }
        return dp[curr][flag] = cnt; // 자기 자신 제외
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
    dfs(1);
    // 루트가 얼리어답터일 때와, 루트가 얼리어답터가 아닐 때 중 최소값
    cout << min(getEA(1, 1), getEA(1, 0));
}