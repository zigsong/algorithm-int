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

// 전체 타일링에서 대칭 타일링을 빼서 문제 해결
int asymmetric(int width)
{
    // 개수 홀수인 경우 중앙 세로로 채우고 나머지 반을 채울 수 있는 경우의 수가 대칭인 경우의 수임
    // 전체 경우의 수에서 n이 홀수이며 대칭인 경우 제외
    if (width % 2 == 1)
        return (tiling(width) - tiling(width / 2) + MOD) % MOD;
    int ret = tiling(width);
    // 전체 경우의 수에서 n이 짝수이고 절반으로 나뉜 부분이 대칭인 경우 제외
    ret = (ret - tiling(width / 2) + MOD) % MOD;
    // 전체 경우의 수에서 n이 짝수이고 정가운데 세로줄이 가로 타일로 덮인 대칭 경우 제외
    ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
    return ret;
}

// 직접 비대칭 타일링의 수를 세는 동적 계획법
int cache2[101];
// 2*width 크기의 사각형을 채우는 비대칭 방법의 수 반환
int asymmetric2(int width)
{
    // 기저 사례 : 너비가 2 이하인 경우
    if (width <= 2)
        return 0;
    // 메모이제이션
    int &ret = cache2[width];
    if (ret != -1)
        return ret;
    ret = asymmetric2(width - 2) % MOD;
    ret = (ret + asymmetric2(width - 4)) % MOD;
    ret = (ret + tiling(width - 3)) % MOD;
    ret = (ret + tiling(width - 3)) % MOD;
    return ret;
}
