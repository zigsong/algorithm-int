// 8.2 메모이제이션을 이용한 이항계수의 계산

// -1 로 초기화된 cache (size 는 n 과 r 의 값에 따라 정한다.)
// 결과 값이 양수만 나오는 경우에만 쓸 수 있다.
int cache[30][30]; 

int bino2(int n, int r) {
    // 기저 사례
    if (r == 0 || n == r) return 1;
    // nCr 을 그 전에 계산 했는지 확인하고, 초기값인 -1 이 아닌 경우 계산 안하고 바로 반환
    if (cache[n][r] != -1) 
        return cache[n][r];
    
    return cache[n][r] = bino2(n-1, r-1) + bino2(n-1, r);
}