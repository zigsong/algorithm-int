#include <iostream>

using namespace std;

int n;
int countCache[100][100];
int count(int y, int x) {
  if(y == n-1) return 1;
  
  int& ret = countCache[y][x];
  if(ret != -1) return ret;
  
  ret = 0;
  // 특정 부분 path의 합이 같을 때 중복 저장되는 문제를 방지
  if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
  if(path2(y+1, x+1) <= path2(y+1, x)) ret += count(y+1, x);
  
  return ret;
}

// temps
int path2(int dy, int dx) {
  return 0; 
}