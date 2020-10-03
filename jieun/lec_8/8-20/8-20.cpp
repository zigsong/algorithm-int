#include <iostream>

using namespace std;

// 8-16
const int MOD = 1000000007;
int cache[101];

int tiling(int width) {
  if(width <= 1) return 1;
  
  int& ret = cache[width];
  if(ret != -1) return ret;
  return ret = (tiling(width-2) + tiling(width-1)) % MOD;
}

// ---
int cache2[101];

int asymmetric2(int width) {
  if(width <= 2) return 0;

  int& ret = cache2[width];
  if(ret != -1) return ret;

  ret = asymmetric2(width-2) % MOD;
  ret = (ret + asymmetric2(width-4)) % MOD;
  ret = (ret + tiling(width-3)) % MOD;
  ret = (ret + tiling(width-3)) % MOD;
  // 결국 아래와 같은 코드
  // ret = (a) + (b) + (c) + (d)
  
  return ret;
}