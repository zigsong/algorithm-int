#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

const int INF = 987654321;
// A[]: 양자화해야 하는 수열(정렬된 상태)
// pSum[] : A[]의 부분합을 저장
// pSqSum[] : A[] 제곱의 부분합 저장
int n;
int A[101], pSum[101], pSqSum[101];
// A를 정렬하고 각 부분합 계산
void precalc()
{
    sort(A, A + n);
    pSum[0] = A[0];
    pSqSum[0] = A[0] * A[0];
    for (int i = 1; i < n; ++i)
    {
        pSum[i] = pSum[i - 1] + A[i];
        pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
    }
}
// A[lo]..A[hi]  구간을 하나의 숫자로 표현할 때 최소 오차 합을 계산
int minError(int lo, int hi)
{
    // 부분합을 이용해 A[lo] ~ A[hi]까지의 합 구함
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
    // 평균 반올림한 값으로 수 표현
    int m = int(0.5 + (double)sum / (hi - lo + 1));
    // sum(A[i]-m)*2를 전개한 결과를 부분합으로 표현
    int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
    return ret;
}

int cache[101][11];
int quantize(int from, int parts)
{
    // 기저 사례 : 모든 숫자 양자화
    if (from == n)
        return 0;
    // 기저 사례 : 숫자는 남았는데 묶을 수 없음
    if (parts == 0)
        return INF;
    int ret & = cache[from][parts];
    if (ret != -1)
        return ret;
    ret = INF;
    // 조각의 길이를 변화시켜가며 최소치 찾기
    for (int partSize = 1; from + partSize <= n; ++partSize)
        // 현재 조각의 오차와 그 이후 양자화 재귀
        ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
    return ret;
}