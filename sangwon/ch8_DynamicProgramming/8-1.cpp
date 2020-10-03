// 8.1 재귀 호출을 이용한 이항 계수의 계산

int bino(int n, int r) {
    if (r == 0 || n == r) return 1;
    return bino(n-1, r-1) + bino(n-1, r); 
    // 이러면 한번 계산한 bino 를 중복해서 계산할 수 있음
}