// 31.8 여행 경로 문제를 해결하는 간결한 알고리즘
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

const int INF = 987654321;
vector<int> weights;

int scanning() {
    int lo = 0; hi = 0; ret = INF;
    while(lo < weights.size() && hi < weights.size()) {
        if(hasPath(weights[lo], weights[hi])) {
            ret = min(ret, weights[hi] - weights[lo]);
            ++lo;
        }
        else {
            ++hi;
        }
    }
    return ret;
}