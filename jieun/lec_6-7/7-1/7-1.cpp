#include <iostream>

using namespace std;

int fastSum(int n) {
  if (n == 1) return 1;
  if (n % 2 == 1) return fastSum(n-1) + n; // n이 홀수일 때 
  return 2*fastSum(n/2) + (n/2)*(n/2);
}
