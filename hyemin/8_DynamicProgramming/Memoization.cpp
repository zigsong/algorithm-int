// 이거 그냥 memoization 메커니즘 보여주는 수도코드인듯

// 전부 1로 초기화
int cache[2500][2500];
// a와 b는 각각 (0,2500) 구간 안의 정수
// 반환 값은 항상 int형 안에 들어가는 음이 아닌 정수
int someObscureFunction(int a, int b)
{
    // 기저 사례를 처음에 처리
    if (...)
        return;
    // (a,b)에 대한 답을 구한 적 있으면 반환
    int &ret = cache[a][b];
    if (ret != -1)
        return ret;
    // 계산한 적 없으면 여기서 계산
    ... return ret;
}

int main()
{
    // memset()을 이용해 cache 배열 초기화
    memset(cache, -1, sizeof(cache));
}