// <see cref="https://www.acmicpc.net/problem/1992" />

#include <iostream>

using namespace std;

int n;
int arr[64][64];

int quadTree(int n, int y, int x) {
  if (n == 1) {
    cout << arr[y][x];
    return 0;
  }
  int find = arr[y][x];
  int half = n / 2;
  
  for (int i=y; i<y+n; i++) { // 다음 사분면으로 옮겨감
    for (int j=x; j<x+n; j++) { // 다음 사분면으로 옮겨감 
      if (find != arr[i][j]) {
        cout << "(";
        quadTree(half, y, x);
        quadTree(half, y, x+half);
        quadTree(half, y+half, x);
        quadTree(half, y+half, x+half);
        cout << ")";
        return 0;
      }
    }
  }
  cout << find;
  return 0;
}

int main() {
  cin >> n;

  for (int i=0; i<n; i++) {
    string line;
    cin >> line;  
    for (int j=0; j<n; j++) {
      arr[i][j] = line[j] - '0';
    }
  }
  
  quadTree(n, 0, 0);

  return 0;
}