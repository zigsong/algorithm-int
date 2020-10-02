#include <iostream>
#include <string>
#include <vector>

int n;
int cache[100], S[100];

int lis2(int start) {
    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start + 1; next < n; ++next) 
        if(S[start] < S[next])
            ret = max(ret, lis2(next) + 1);
    return ret;
}