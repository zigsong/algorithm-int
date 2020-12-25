// 31.5 변형한 크루스칼 알고리즘으로 여행 경로 문제 해결하기
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

const int INF = 987654321;
vector<int> weights;
vector<pair<int, pair<int,int> > > edges;

int kruskalMinUpperBound(int low) {
    DisjointSet sets(V);
    for(int i = 0; i < edges.size(); ++i) {
        if(edges[i].first < weights[low]) continue;
        sets.merge(edges[i].second.first, edges[i].second.second);
        if(sets.find(0) == sets.find(V - 1))
            return edges[i].first;
    }
    return INF;
}