#include <iostream>
#include <algorithm>

using namespace std;

const int INF =987654321l;

int n;
int A[101], pSum[101], pSqSum[101];

void precalc() {
  sort(A, A+n);
  pSum[0] = A[0];
  pSqSum[0] = A[0] * A[0];
  for(int i=1; i<n; ++i) {
    pSum[i] = pSum[i-1] + A[i];
    pSqSum[i] = pSqSum[i-1] + A[i]*A[i];
  }
}

// A[lo]...A[hi] 구간을 하나의 숫자로 표현할 때 최소 오차 합을 계산
int minError(int lo, int hi) {
  int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
  int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
  int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
  int m = int(0.5 + (double)sum / (hi-lo+1));
  int ret = sqSum - 2 * m * sum + m * m * (hi-lo+1);
  return ret;
}

int cache[101][11];
int quantize(int from, int parts) {
  if(from == n) return 0;
  // 숫자는 아직 남았는데 더 묶을 수 없을 때
  if(parts == 0) return INF;
  
  int& ret = cache[from][parts];
  if(ret != -1) return ret;

  ret = INF;
  // for(int partSize=1; from+partSize<=n; ++partSize) {
  //   ret min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1));
  // }
  return ret;
}