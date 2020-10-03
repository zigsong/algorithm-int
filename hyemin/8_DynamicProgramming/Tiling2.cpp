#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

const int MOD = 1000000007;
int cache[101];
//2*width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지 반환
int tiling(int width)
{
    // 기저 사례 : width가 1 이하일 때
    if (width <= 1)
        return 1;
    // 메모이제이션
    int &ret = cache[width];
    if (ret != -1)
        return ret;
    return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}