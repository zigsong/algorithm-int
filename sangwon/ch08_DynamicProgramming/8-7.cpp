// 8.7 와일드카드 문제를 해결하는 동적 계획법 알고리즘

// -1 로 초기화된 cache, 문자열의 길이가 최대 100 이므로
int cache[101][101];

// W: 패턴 (ex. he*p) , S: 비교할 문자열 (ex. hellp)
string W, S;

bool matchMemoized(int w, int s) {
    // 메모이제이션 
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    while(s < S.size() && w < W.size() && (W[w] == '?' W[w] == S[s])) {
        ++w;
        ++s;
    }
    // w 가 끝에 도달했을 때, s 도 끝에 도달했다면 true, 아니면 false
    // 이 아래 코드는 앞 문제와 논리적으로 같다
    if(w == W.size()) return ret = (s == S.size());

    if(W[w] == '*')
        for(int skip = 0; skip+s <= S.size(); ++skip)
            if(matchMemoized(w+1, s+skip))
                return ret = 1;  
                // match 가 되면 cache 의 해당 값을 1 로 바꿈, 
                // 패턴이 맞는지 다시 계산할 필요 없다.
    return ret = 0;
}

