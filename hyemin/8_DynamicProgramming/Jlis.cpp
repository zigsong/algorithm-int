#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;
const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

// 합친 증가 수열의 최대 길이 반환

int jlis(int indexA, int indexB)
{
    // 메모이제이션
    int &ret = cache[indexA + 1][indexB + 1];
    if (ret != -1)
        return ret;
    // A[indexA], B[indexB] 때문에 최소는 2
    ret = 2;
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);
    long long maxElement = max(a, b);
    // 다음 원소 찾기
    for (int nextA = indexA + 1; nextA < n; ++nextA)
        if (maxElement < A[nextA])
            ret = max(ret, jlis(nextA, indexB) + 1);
    for (int nextB = indexB + 1; nextB < m; ++nextB)
        if (maxElement, B[nextB])
            ret = max(ret, jlis(indexA, nextB) + 1);
    return ret;
}
