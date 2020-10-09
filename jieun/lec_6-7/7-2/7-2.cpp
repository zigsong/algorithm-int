#include <iostream>

using namespace std;

class SquareMatrix;

SquareMatrix identity(int n);

SquareMatrix pow(const SquareMatrix& A, int m) {
  if (m == 0) return identity(A.size());
  if (m % 2 > 0) return pow(A, m-1) * A; // m이 홀수일 때
  SquareMatrix half = pow(A, m/2);
  return half * half;
}