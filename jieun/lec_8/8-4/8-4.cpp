#include <iostream>

using namespace std;

int n, board[100][100];
bool jump(int y, int x) {
  if (y >= n || x >= n) return false;
  if(y == n-1 && x == n-1) return true;
  // jumpSize = 그 칸에 적혀 있는 숫자!
  int jumpSize = board[y][x];
  // bool값으로 반환, 둘 중 하나만 true여도 true
  return jump(y+jumpSize, x) || jump(y, x+jumpSize);
}