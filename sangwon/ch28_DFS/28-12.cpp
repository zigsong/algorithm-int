// 28.12 회의 시간으로부터 2-SAT 문제의 합의 그래프 만들기

#include <map>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > adj;
bool disjoint(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second <= b.first || b.second <= a.first;
}

void makeGraph(const vector<pair<int, int>>& meetings) {
    int vars = meetings.size();
    adj.clear(); adj.resize(vars*2);
    for(int i = 0; i < vars; i += 2) {
        int j = i + 1;
        adj[i * 2 + 1].push_back(j * 2);
        adj[j * 2 + 1].push_back(i * 2);
    }
    for(int i = 0; i < vars; ++i)
        for(int j = 0; j < i; j++) {
            if(!disjoint(meetings[i], meetings[j])) {
                adj[i * 2].push_back(j * 2 + 1);
                adj[j * 2].push_back(i * 2 + 1);
            }
        }
}