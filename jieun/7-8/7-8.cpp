#include <iostream>
#include <vector>

using namespace std;

vector<int> height;

int solve(int left, int right) {
  if (left == right) return height[left]; // base case: 판자가 1개밖에 없는 경우
  int mid = (left + right) / 2;
  int ret = max(solve(left, mid), solve(mid+1, right));
  
  int lo = mid, hi = mid+1;
  int h = min(height[lo], height[hi]); // Q. 왜 작은 쪽으로 가는?
  ret = max(ret, h*2);

  while (left<lo || hi<right) {
    if (hi<right && (lo == left || height[lo-1] < height[hi+1])) {
      ++hi;
      h = min(h, height[hi]);
    } else {
      --lo;
      h = min(h, height[lo]);
    }
    ret = max(ret, h*(hi-lo+1));
  }
  return ret;
}