// 8.11 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (1)

int n;
int cache[100], S[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis2(int start) {
    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start + 1; next < n; ++next) 
        if(S[start] < S[next])
            ret = max(ret, lis2(next) + 1);
    return ret;
}

int main(){
    int maxLen = 0;
    for(int begin = 0; begin < n; ++begin)
        maxLen = max(maxLen, lis2(begin));
}