#include <iostream>
#include <vector>

using namespace std;

int n;
int cache[100], S[100];

int lis2(int start) {
  int& ret = cache[start];
  if (ret != -1) return ret;
  // S[start]는 항상 있기 때문에 최하 길이는 1
  ret = 1;
  for (int next=start+1; next<n; ++next) {
    if (S[start] <S[next]) {
      ret = max(ret, lis2(next)+1);
    }
    return ret;
  }
}