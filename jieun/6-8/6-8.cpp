#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS+1] = {

};

bool areAligned(const vector<int>& clocks) {
  for (int clock : clocks) {
    if (clock != 12) return false;
  }
};

void push(vector<int>& clocks, int swtch) {
  for (int clock=0; clock<CLOCKS; ++clock) {
    if (linked[swtch][clock] == 'x') {
      clocks[clock] += 3;
      if (clocks[clock] == 15) clocks[clock] = 3;
    }
  }
}

// 솔직히 이건 잘 모르겠다.
int solve(vector<int>& clocks, int swtch) {
  // 지금 누르는 스위치가 마지막 스위치라면, 모두 정렬되어 있는지 확인 후 리턴
  if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF; 

  int ret = INF;
  // 스위치를 0번~3번 누르는 경우 
  for (int cnt=0; cnt<4; ++cnt) {
    ret = min(ret, cnt+solve(clocks, swtch+1));
    push(clocks, swtch);
  }

  return ret;
}