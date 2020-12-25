// 31.4 이분 검색으로 minUpperBound() 구현하기
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

const int INF = 987654321;
vector<int> weights;

bool hasPath(int lo, int hi);
int binarySearchMinUpperBound(int low) {
    int lo = low - 1, hi = weights.size();
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(hasPath(weights[low], weights[mid]))
            hi = mid;
        else
            lo = mid;
    }
    if(hi == weights.size()) return INF;
    return weights[hi];
}