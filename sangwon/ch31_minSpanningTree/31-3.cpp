// 31.3 minUpperBound 를 이용해 여행 경로 문제 해결하기
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V, E;

vector<pair<int, int> > adj[MAX_V];
vector<int> weights;

int minUpperBound(int low);

int minWeightDifference() {
    int ret = INF;
    for(int i = 0; i < weight.size(); ++i)
        ret = min(ret, minUpperBound(i) - weights[i]);
    return ret;
}