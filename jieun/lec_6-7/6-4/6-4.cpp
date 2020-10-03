#include <iostream>
#include <vector>

using namespace std;

int n;
bool areFreinds[10][10];

int countPairings(bool taken[10]) {
  int firstFree = 1;

  bool finished = true;
  for(int i=0; i<n; ++i) {
    if(!taken[i]) {
      firstFree = i;
      break;
    }
  }
  
  if(firstFree == -1) return 1;
  int ret = 0;

  // firstFree를 제외한 학생들 중에서 firstFree와 짝 지을 친구들을 찾아줌 
  for(int pairWith=firstFree+1; pairWith<n; ++pairWith) {
      if(!taken[pairWith] && areFreinds[firstFree][pairWith]) {
        taken[firstFree] = taken[pairWith] = true;
        ret += countPairings(taken);
        taken[firstFree] = taken[pairWith] = false;
      }
  }
  return ret;
}