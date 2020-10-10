#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 각 판자의 높이를 저장하는 배열
vector<int> h;

int solveStack() {
  // 지워지지 않은 판자들을 내버려 둘 스택
  stack<int> remaining;
  // 오른쪽 끝에 높이 0인 가상의 판자 추가 (다른 모든 판자의 right[]를 정의해 주는 역할)
  h.push_back(0);
  int ret = 0;
  
  for (int i=0; i<h.size(); ++i) {
    // 남아 있는 판자들(p.631의 그림에서, 현재 단계의 왼쪽 판자들) 중 오른쪽 끝 판자가 h[i]보다 높다면
    // 이 판자(남아 있는 판자들 중 오른쪽 끝 판자)의 최대 사각형은 i(현재 단계)에서 끝난다
    while(!remaining.empty() && h[remaining.top()] >= h[i]) {
      // 그 오른쪽 끝 판자에서의 최대 사각형 넓이를 계산해야 하므로 j에 담아 둠 
      int j = remaining.top(); 
      remaining.pop();
      // j가 유일한 판자라고 생각하고 width를 초기화
      int width = -1;
      if (remaining.empty()) {
        width = i;
      } else {
        width = (i - remaining.top() -1);
      }
      ret = max(ret, h[j] * width);
    }
    remaining.push(i);
  }
  return ret;
}