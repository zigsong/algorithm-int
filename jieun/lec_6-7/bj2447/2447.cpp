// <see cref="https://www.acmicpc.net/problem/2447" />

#include <iostream>

using namespace std;

void asterisk(int x, int y, int size) {
  if ((x/size)%3==1 && (y/size)%3==1) cout << " "; // size만 줄여나가는 과정에서, num의 전 범위를 돌고 있는 x, y가 현재 size보다 큰 경우에 해당하는 계산
  else {
    if (size/3 == 0) cout << "*"; // size를 계속 3으로 나누다 size == 1이 되었을 때 
    else asterisk(x, y, size/3);
  }
}

int main() {
  int num;
  cin >> num;
  
  for (int i=0; i<num; i++) {
    for (int j=0; j<num; j++) {
      asterisk(i, j, num);
    }
    cout << "\n";
  }
  
  return 0;
}
