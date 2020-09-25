#include <iostream>
#include <vector> 

int num;
int input[13];
int lotto[6];

using namespace std;

void dfs(int n, int depth) {
  if (depth == 6) {
    for (int i=0; i<6; i++) {
      cout << lotto[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i=n; i<num; i++) {
    lotto[depth] = input[i];
    dfs(i+1, depth+1);
  }
}

int main() {
  while(1) { // equivalent to 'while(true)'
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