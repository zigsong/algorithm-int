// 8.13 합친 LIS 문제를 해결하는 동적 계획법 알고리즘

// 각각 따로 해서 합치면, (1 2 4) (4 5 6) 일 때 6이 나오지만
// 실제 답은 (1 2 4 5 6) 으로 5가 나와야 한다. 따라서 처음부터 모든 걸 고려하는 알고리즘을 짜야 한다.

// 입력이 32비트 부호 있는 정수의 모든 값을 가질 수 있으므로
// 인위적인 최소치는 64비트여야 한다. (?)
const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];
// min(A[indexA], B[indexB]). max(A[indexA], B[indexB]) 로 시작하는
// 합친 증가 부분 수열의 최대 길이를 반환한다.
// 단 indexA == indexB == -1 혹은 A[indexA] != B[indexB] 라고 가정한다.
int jlis(int indexA, int indexB) {
    // 메모이제이션, cache 도 2차원 배열
    int& ret = cache[indexA+1][indexB+1];
    if(ret != -1) return ret;
    // A[indexA], B[indexB]가 이미 존재하므로 2개는 항상 있다.
    ret = 2;
    long long a = (indexA == -1 ? NEGINF : A[indexA]); // -1이 아니면 A[indexA], -1 이면 NEGINF (가장 작은 값)
    long long b = (indexB == -1 ? NEGINF : B[indexB]); // -1이 아니면 B[indexB], -1 이면 NEGINF
    // 둘 중에 더 큰 값을 maxElement 에 저장한다. 이를 통해 처음에 언급한 문제를 해결할 수 있다.
    // 위에서 하나라도 NEGINF 가 나오면 나머지 하나가 maxElement 가 된다.
    long long maxElement = max(a, b);
    // 다음 원소를 찾는다.
    for(int nextA = indexA + 1; nextA < n; ++nextA)
        if(maxElement < A[nextA])
            ret = max(ret, jlis(nextA, indexB) + 1);
    for(int nextB = indexB + 1; nextB < n; ++nextB)
        if(maxElement < B[nextB])
            ret = max(ret, jlis(indexA, nextB) + 1);
    
    return ret;
}