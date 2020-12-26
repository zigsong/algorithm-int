// 31.7 여행 경로 문제를 해결하는 무식한 알고리즘을 최적화하기
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

const int INF = 987654321;
vector<int> weights;

int optimized() {
    int ret = INF, foundPathUsing = 0;
    for(int lo = 0; lo < weights.size(); lo++) {
        bool foundPath = false;
        for(int hi = foundPathUsing; hi < weights.size(); ++hi) {
            if(hasPath(weights[lo], weights[hi])) {
                ret = min(ret, weights[hi] - weights[lo]);
                foundPath = true;
                foundPathUsing = hi;
                break;
            }
        }
        if(!foundPath) break;
    }
    return ret;
}