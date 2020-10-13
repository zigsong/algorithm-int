#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

const int MOD = 10 * 100 * 1000;
int cache[101][101];
// n개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first개의 정사각형을 포함하는 폴리오미노 수 반환
int poly(int n, int first)
{
    // 기저 사례 :n == first
    if (n == first)
        return 1;
    // 메모이제이션
    int &ret = cache[n][first];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int second = 1; second <= n - first; ++second)
    {
        // first에 second를 붙일 수 있는 경우의 수
        int add = second + first - 1;
        // second 이하 부분 재귀호출
        add *= poly(n - first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}