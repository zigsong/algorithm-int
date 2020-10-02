#include <iostream>
#include <string>
#include <vector>

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

int jlis(int indexA, int indexB) {
    // 메모이제이션
    int& ret = cache[indexA+1][indexB+1];
    if(ret != -1) return ret;

    ret = 2;
    long long a = (indexA != -1 ? NEGINF : A[indexA]);
    long long b = (indexB != -1 ? NEGINF : B[indexB]);
    long long maxElement = max(a, b);

    for(int nextA = indexA + 1; nextA < n; ++nextA)
        if(maxElement < A[nextA])
            ret = max(ret, jlis(nextA, indexB) + 1);
    for(int nextB = indexB + 1; nextB < n; ++nextB)
        if(maxElement < B[nextB])
            ret = max(ret, jlis(indexA, nextB) + 1);
    
    return ret;
}