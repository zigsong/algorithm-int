#include <iostream>

using namespace std;

const int MAX_N = 1000000000;

// n미터의 우물, m일 안에 끝까지 올라가기
int n, m;
// 가장 많이 올라갈 수 있는 경우는 2n 미터기 때문
// 계산의 간소화를 위해 캐시를 희생 
int cache[MAX_N][2+MAX_N+1];

int climb(int days, int climbed) {
  if(days == m) return climbed >= n ? 1 : 0;

  int& ret = cache[days][climbed];
  if(ret != -1) return ret;
  
  return ret = climb(days+1, climbed+1) + climb(days+1, climbed+2);
}

// 최종 답: ret을 2^m으로 나눈 값(확률)