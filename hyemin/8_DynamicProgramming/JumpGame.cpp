// 외발 뛰기 문제를 해결하는 재귀 호출 알고리즘

int n, board[100][100];
bool jump(int y, int x)
{
    // 기저 사례 : 게임판 밖을 벗어난 경우
    if (y >= n || x >= n)
        return false;
    // 기저 사례 : 마지막 칸에 도착한 경우
    if (y == n - 1 && x == n - 1)
        return true;
    int jumpSize = board[y][x];
    return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

// 외발 뛰기 문제를 해결하는 동적 계획법 알고리즘
int cache[100][100];
int jump2(int x, int y)
{
    // 기저 사례 처리
    if (y >= n || x >= n)
        return 0;
    if (y == n - 1 && x == n - 1)
        return 1;
    // 메모이제이션
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;
    int jumpSize = board[y][x];
    return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}