// 8.5 외발 뛰기 문제를 해결하는 동적 계획법 알고리즘

int n, board[100][100];

// -1 로 초기화된 cache, board 의 사이즈와 같다.
int cache[100][100];

// ret 을 리턴받기 때문에 bool 함수가 아니라 int 함수
int jump2(int y, int x) {
    // 기저 사례 처리
    if(y >= n || x >= n) return 0;
    if(y == n-1 && x == n-1) return 1;
    
    // 메모이제이션
    // cache 의 해당 위치 값을 참조 변수인 ret 에 대입 
    int& ret = cache[y][x];
    
    // 이미 연산된 값이 있는지 확인한다. ret 에 들어간 값 역시 0 or 1
    // 이러면 굳이 bool 함수로 쓰지 않은 이유가?
    if(ret != -1) return ret;
    // cache 에 연산 결과가 없으면 아래 연산 실시
    int jumpSize = board[y][x];
    // ret 에 재귀 호출의 결과값 대입, 재귀가 다 일어나고 0 or 1 의 값을 반환하면 
    // 그제서야 층층이 올라가며 처음 단에서 return 이 일어남
    return ret = (jump2(y + jumpSize, x)) || jump2(y, x + jumpSize);
    // 이때는 아직 ret 에 무슨 값이 들어갈지 모르므로, return 이 실제로 일어나려면 = 뒤의 연산이 끝나야 하지 않나?
}
