#include <iostream>

using namespace std;

int total;
int cnt = 0;

bool hansoo(int num) { // if 123
  if (num < 100) return true;

  int n1, n2, n3;

  n1 = num % 10; // 3
  n2 = (num / 10) % 10; // 2
  n3 = num / 100; // 1

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