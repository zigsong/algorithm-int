#include <iostream>

using namespace std;

// 한 칸에 들어갈 숫자의 최대치 
const int MAX_NUMBER = 999999;
int n, triangle[100][100];
int cache[100][100][MAX_NUMBER*100+1];

int path1(int y, int x, int sum) {
  if (y == n-1) return sum + triangle[y][x];
  int& ret = cache[y][x][sum];
  if (ret != -1) return ret;
  sum += triangle[y][x];
  return ret = max(path1(y+1, x+1, sum), path1(y+1, x, sum));
}