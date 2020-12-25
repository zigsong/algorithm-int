// 31.6 여행 경로 문제를 해결하는 가장 무식한 알고리즘
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

const int INF = 987654321;
vector<int> weights;

int brute() {
    int ret = INF;
    for(int lo = 0; lo < weights.size(); ++lo)
        for(int hi = lo; hi < weights.size(); ++hi) {
            if(hasPath(weights[lo], weights[hi])) {
                ret = min(ret, weights[hi] - weights[lo]);
                break;
            }
        }
    return ret;
}