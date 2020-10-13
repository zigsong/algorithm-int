#include <iostream>

using namespace std;

int n, board[100][100];
int cache[100][100];

int jump2(int y, int x) {
  if (y>=n || x>=n) return 0;
  if (y==n-1 && x==n-1) return 1;
  int& ret = cache[y][x];
  if (ret != -1) return ret;
  int jumpSize = board[y][x];
  // 값을 반환 후 배열에 저장(캐싱)
  // cache가 -1이기 때문에 이 함수를 반환 
  // ret가 -1일 경우에만 연산을 수행해서, 0(false) 또는 1(true)을 리턴
  return ret = (jump2(y+jumpSize, x) || jump2(y, x+jumpSize));
}