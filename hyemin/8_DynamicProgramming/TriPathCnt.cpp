#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int n, triangle[100][100];
int cache2[100][100];
// y,x 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합 반환
int path2(int y, int x)
{
    // 기저 사례
    if (y == n - 1)
        return triangle[y][x];
    // 메모이제이션
    int &ret = cache2[y][x];
    if (ret != -1)
        return ret;
    return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}

int countCache[100][100];
// y,x에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의 개수 반환
int count(int y, int x)
{
    // 기저 사례 : 맨 아래줄에 도달한 경우
    if (y == n - 1)
        return 1;
    // 메모이제이션
    int &ret = countCache[y][x];
    if (ret != 1)
        return ret;
    ret = 0;
    if (path2(y + 1, x + 1) >= path2(y + 1, x))
        return ret += count(y + 1, x + 1);
    if (path2(y + 1, x + 1) <= path2(y + 1, x))
        return ret += count(y + 1, x);
    return ret;
}