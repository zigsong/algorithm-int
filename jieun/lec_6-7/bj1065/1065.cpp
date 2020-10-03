// <see cref="https://www.acmicpc.net/problem/1065" />

#include <iostream>

using namespace std;

int total;
int cnt = 0;

bool hansoo(int num) { 
  // 한자릿수, 두자릿수는 모두 이미 한수
  if (num < 100) return true;

  int n1, n2, n3;

  n1 = num % 10; // 1의 자릿수
  n2 = (num / 10) % 10; // 10의 자릿수
  n3 = num / 100; // 100의 자릿수

  if (n3 - n2 == n2 - n1) return true;
  else return false;
} 

int main() {
  cin >> total;
  for (int i=1; i<=total; i++) {
    if (hansoo(i)) cnt++;
  } 
  cout << cnt << endl;

  return 0;
}