//
// Created by songji on 2020/11/12.
//

#include <vector>

using namespace std;

vector<vector<int> > adj;
// 각 정점의 발견 순서, -1로 초기화
vector<int> discoverd;
// 각 정점이 절단점인지 여부, false로 초기화
vector<bool> isCutVertex;
int counter = 0;

int findCutVertex(int here, bool isRoot) {
    discoverd[here] = counter++;
    int ret = discoverd[here];

    // 루트인 경우의 절단점 판정을 위해 자손 서브트리의 개수 세기
    int children = 0;
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];
        if (discovered[there] == -1) {
            ++children;
            // 이 서브트리에서 갈 수 있는 가장 높은 정점의 번호
            int subtree = findCutVertex(there, false);
            // 그 노드가 자기 자신 이하에 있다면(더 나중에 발견됐다면) 현재 위치는 절단점!
            if (!isRoot && subtree > discoverd[here]) isCutVertex[here] = true;
            ret = min(ret, subtree);
        } else ret = min(ret, discoverd[there]);
    }
    if (isRoot) isCutVertex[here] = (children >= 2);
    return ret;
}