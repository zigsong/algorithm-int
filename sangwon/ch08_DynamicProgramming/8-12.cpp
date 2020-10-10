// 8.12 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (2)
// 사실 이 코드는 잘 이해가 되지 않는다
// 앞의 코드에서 맨 처음 start 를 0으로 지정하면 하나하나 다 고려하지 않나?

int n;
int cache[101], S[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis3(int start) {
    int& ret = cache[start + 1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start+1; next < n; ++next)
        if(start == -1  || S[start] < S[next])
            ret = max(ret, lis3(next) + 1);
    return ret;
}
