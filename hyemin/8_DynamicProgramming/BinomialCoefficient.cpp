
// 분할 정복을 활용한 이항 계수의 계산
int bino(int n, int r)
{
    // 기저 사례 : n=r (모든 원소를 다 고르는 경우) or r=0 (고를 원소가 없는 경우)
    if (r == 0 || n == r)
        return 1;
    return bino(n - 1, r - 1) + bino(n - 1, r);
}

// 메모이제이션을 활용한 이항 계수의 계산
// -1로 초기화
int cache[30][30];
int bino2(int n, int r)
{
    // 기저 사례
    if (r == 0 || n == r)
        return 1;
    // -1이 아니라면 이미 계산했던 값이니 그 값 반환
    if (cache[n][r] != -1)
        return cache[n][r];
    // 직접 계산한 뒤 배열에 저장
    return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}