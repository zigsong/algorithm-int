#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <numeric>
#include <iostream>

using namespace std;

// 최대 증가 부분 수열 문제를 해결하는 완전 탐색 알고리즘

int lis(const vector<int> &A)
{
    // 기저 사례 : A가 비어 있을 때
    if (A.empty())
        return 0;
    int ret = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        vector<int> B;
        for (int j = i + 1; j < A.size(); ++j)
            if (A[i] < A[j])
                B.push_back(A[j]);
        ret = max(ret, 1 + lis(B));
    }
    return ret;
}

// 시작하는 부분의 증가 수열 최대치를 구하는 동적 계획법 알고리즘 1

int n;
int cache[100], S[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이 반환
int lis2(int start)
{
    int &ret = cache[start];
    if (ret != -1)
        return ret;
    // 항상 S[start]는 있기 때문에 길이는 최소 1
    ret = 1;
    for (int next = start + 1; next < n; ++next)
        if (S[start] < S[next])
            ret = max(ret, lis2(next) + 1);
    return ret;
}
// lis2()를 호출할 때 항상 증가 부분 수열의 시작 위치 start를 지정해야 함
// 처음에 호출할 때 각 위치를 순회하면서 최대 값을 찾는 코드 필요

int cache2[101], S[100];
int lis3(int start)
{
    int &ret = cache2[start + 1];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int next = start + 1; next < n; ++next)
        if (start == -1 || S[start] < S[next])
            ret = max(ret, lis3(next) + 1);
    return ret;
}