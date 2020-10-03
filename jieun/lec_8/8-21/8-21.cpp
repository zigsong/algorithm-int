#include <iostream>

using namespace std;

const int MOD = 10*1000*1000;
int cache[101][101];

int poly(int n, int first) {
  if(n == first) return 1;

  int& ret = cache[n][first];
  if(ret != -1) return ret;
  
  ret = 0;

  // p.268 수식 참조
  for(int second=1; second<=n-first; ++second) {
    int add = second + first - 1;
    add *= poly(n-first, second);
    add %= MOD;
    ret += add;
    ret %= MOD;
  }

  return ret;
}