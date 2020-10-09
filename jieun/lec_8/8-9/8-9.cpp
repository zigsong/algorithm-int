#include <iostream>

using namespace std;

int n, triangle[100][100];
int cache2[100][100];

int path2(int y, int x) {
  if (y == n-1) return triangle[y][x];
  int& ret = cache2[y][x];
  if (ret != -1) return ret;
  return ret = max(path2(y+1, x), path2(y+1, x+1)) + triangle[y][x];
}