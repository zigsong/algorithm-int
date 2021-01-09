//
// Created by songji on 2021/01/05.
//
#include <iostream>
#include <string.h>

using namespace std;

const int MOD = 10007;
int cache[1001];

int tiling(int n) {
    if (n <= 1) return 1;
    int& ret = cache[n];
    if (ret != -1) return ret;
    return ret = (tiling(n-2) + tiling(n-1)) % MOD;
}

int main() {
    int n;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << tiling(n);
}