#include <iostream>
#include <algorithm>

// int n;
// int count = 0;

// int main() {
//   std::cin >> n;

//   while(n > 1) {
//     if(n % 3 == 0) n /= 3;
//     else if(n % 2 == 0) n /= 2;
//     else n -= 1;
//     count++;
//     if (n == 1) break;
//   }
  
//   std::cout << count;
//   return count;
// }

using namespace std;
int dp[1000001];

int solution(int n) {
  // dp[1]값은 0으로 초기화된 상태, dp[2]부터 시작하여 dp[10]까지 경우의 수 굴려주기
  for(int i=2; i<=n; i++) {
    dp[i] = dp[i-1] + 1; // 1로 뺀 값, count 
    if(i % 2 == 0) dp[i] = min(dp[i/2]+1, dp[i]); // 2로 나눈 게 더 작다면 그 값으로 대체
    if(i % 3 == 0) dp[i] = min(dp[i/3]+1, dp[i]); // 3으로 나눈 게 더 작다면 그 값으로 대체
  }
  return dp[n];
}

int main() {
  dp[1] = 0;
  int n;
  cin >> n;
  
  cout << solution(n);
}

// dp[2] = dp[1]+1 = 1;
// dp[2] = min(dp[1]+1, dp[2]) // -> 1, 1 -> 1

// dp[3] = dp[2]+1 = 2;
// dp[3] = min(dp[1]+1, dp[3]) // -> 1, 2 -> 1

// dp[4] = dp[3]+1 = 2;
// // 이때 dp[2]는 이미 dp에 (캐시로) 저장되어 있음! 
// dp[4] = min(dp[2]+1, dp[4]) // -> 2, 2 -> 2

