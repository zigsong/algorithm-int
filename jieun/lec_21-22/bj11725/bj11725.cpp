#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;

int n;
// what's this? 
// vector는 matrix같은 개념이므로 이중배열처럼 구현 가능
vector<int> v[MAX];
// vector<vector<int>> v;

bool visited[MAX];
int parent[MAX];

void findParent(int num) {
  visited[num] = true;

  for (int i=0; i<v[num].size(); i++) {
    int next = v[num][i];

    if (!visited[next]) {
      parent[next] = num;
      findParent(next);
    }
  }
} 

int main() {
  cin >> n;

  int num1;
  int num2;

  for (int i=0; i<n-1; i++) {
    cin >> num1 >> num2;
    v[num1].push_back(num2);
    v[num2].push_back(num1);
  }

  // for (int i=1; i<=n; i++) {
  //   for (int j=0; j<v[i].size(); j++) {
  //     cout << v[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  
  findParent(1);

  for (int i=2; i<=n; i++) {
    cout << parent[i] << "\n";
  }

  return 0;
}