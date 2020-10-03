// <see cref="https://www.acmicpc.net/problem/6603" />

#include <iostream>
#include <vector> 

int num;
int input[13];
int lotto[6];

using namespace std;

void dfs(int n, int depth) {
  if (depth == 6) { // base case: 6개 다 뽑았다면 
    for (int i=0; i<6; i++) {
      cout << lotto[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i=n; i<num; i++) { // 전체 집합에서 현재 뽑은 수만큼 빼고 다시 loop
    lotto[depth] = input[i];
    dfs(i+1, depth+1);
  }
}

int main() {
  while(1) { // equivalent to 'while(true)' in C++
    cin >> num;
    if (num == 0) break;
    for (int i=0; i<num; i++) {
      cin >> input[i];
    }
    dfs(0, 0);
    cout << endl;
  }
  return 0;
}