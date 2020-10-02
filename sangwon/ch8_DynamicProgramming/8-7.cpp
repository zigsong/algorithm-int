#include <iostream>
#include <string>
#include <vector>

int cache[101][101];

string W, S;

bool matchMemoized(int w, int s) {
    // 메모이제이션
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    while(s < S.size() && w < W.size() && (W[w] == '?' W[w] == S[s])) {
        ++w;
        ++s;
    }

    if(w == W.size()) return ret = (s == S.size());

    if(W[w] == '*')
        for(int skip = 0; skip+s <= S.size(); ++skip)
            if(matchMemoized(w+1, s+skip))
                return ret = 1;
    return ret = 0;
}