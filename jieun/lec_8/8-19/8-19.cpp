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

int asymmetric(int width) {
  // width가 홀수일 때, p.261의 (a)
  if(width % 2 == 1) {
    return (tiling(width) - tiling(width/2) + MOD) % MOD;
  }

  // width가 짝수일 때, 대칭일 수 있는 두 가지 방법을 각각 빼준 ret값을 리턴
  int ret = tiling(width);

  // 아래 두 줄은 아래 한줄과 같은 결과
  // tiling(width) - tiling(width/2) - tiling(width/2-1)
  ret = (ret - tiling(width/2) + MOD) % MOD;
  ret = (ret - tiling(width/2-1) + MOD) % MOD;
  
  return ret;
}