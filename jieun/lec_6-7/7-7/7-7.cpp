#include <iostream>

using namespace std;

// 가장 왼쪽, 오른쪽 판자가 정해져있을 때의 사각형의 넓이 
int bruteforce(const vector<int>& h) { // const reference - call by ref, 함수 내에서 참조값 변경 불가
  int ret = 0;
  int N = h.size();

  for (int left=0; left<N; ++left) {
    int minHeight = h[left];
    for (int right=left; right<n; ++right) {
      minHeight = min(minHeight, h[right]);
      ret = max(ret, (right-left+1) * minHeight);
    }
  } 
  return ret;
}