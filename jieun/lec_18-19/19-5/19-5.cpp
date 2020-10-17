#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct RNG {
  unsigned seed;
  RNG() : seed(1983) {}
  unsigned next() {
    unsigned ret = seed;
    seed =((seed * 214013u) + 2531011u);
    return ret % 10000 + 1;
  }
};

// n = 전체 input의 길이
int countRanges(int k, int n) {
  RNG rng;
  // int rng = RNG();
  queue<int> range;
  int ret = 0, rangeSum = 0;
  for (int i=0; i<n; i++) {
    // tail을 먼저 넣고 head를 뺌 
    int newSignal = rng.next();
    rangeSum += newSignal;
    range.push(newSignal);

    while (rangeSum > k) {
      rangeSum -= range.front();
      range.pop();
    }
    if (rangeSum == k) ret++;
  }
  return ret;
}

