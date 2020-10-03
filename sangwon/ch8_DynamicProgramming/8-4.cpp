// 8.4 외발 뛰기 문제를 해결하는 재귀 호출 알고리즘

// board 는 숫자 판, n은
int n, board[100][100];

bool jump(int y, int x) {
    // 기저사례: 마지막 턴에 도착지로 가는 방법이 없을 때(게임판 밖을 벗어나는 경우)
    if (y >= n || x >= n) return false;
    // 기저사례: 목적지에 도착한 경우
    // 왜 n - 1 ? 0~99 라 그런가?
    if (y == n-1 && x == n-1) return true;

    // 해당 칸에 쓰여있는 만큼 갈 수 있다
    int jumpSize = board[y][x];

    // 재귀 호출을 통해 기저 사례에 도달하기 전까지 이동을 반복한다.
    // 세로, 가로 모두 따지기 때문에, 전체 이동 횟수가 n 이라면 2^n 번 따져봐야한다
    // 이미 가본 칸에 대해선 같은 연산을 반복할 필요가 없다 -> 메모이제이션을 활용하자.
    return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}