#include <iostream>
#include <vector>

using namespace std;

vector<int> height = {3, 8, 8, 8, 8, 6, 7, 5};

int solve(int left, int right) {
  if (left == right) return height[left]; // base case: 판자가 1개밖에 없는 경우
  int mid = (left + right) / 2;
  int ret = max(solve(left, mid), solve(mid+1, right));
  
  int lo = mid, hi = mid+1;
  int h = min(height[lo], height[hi]); // Q. 왜 작은 쪽으로 가는?
  ret = max(ret, h*2); // h*2 = (mid~mid+1)을 밑변으로 하는 사각형의 넓이

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

int main() {
  cout << solve(0, height.size()) << endl;  
}