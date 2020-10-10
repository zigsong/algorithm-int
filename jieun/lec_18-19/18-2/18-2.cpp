#include <iostream>
#include <list>

using namespace std;

void josephus(int n, int k) {
  list<int> survivors;
  for (int i=1; i<=n; ++i) {
    survivors.push_back(i);
  }
  list<int>::iterator kill = survivors.begin();
  while(n > 2) {
    kill = survivors.erase(kill);
    if (kill == survivors.end()) kill = survivors.begin();
    --n;

    // k > n 인 경우 계산 간소화: (k-1)%n
    for (int i=0; i<(k-1)%n; ++i) {
      ++kill;
      // .end()는 실제 맨 뒤가 아니라, 하나 더 뒤 가상의 포인터 (맨 뒤 = .back())
      if (kill == survivors.end()) kill = survivors.begin();
    }
  }
  cout << survivors.front() << " " << survivors.back() << endl;
}

int main() {
  int n, k;
  cin >> n >> k;
  josephus(n, k);
}

// 6, 3 
// 6명의 병사, 1번부터 시작, 시계방향으로 3번 째 살아 있는 사람이 자살
// 1 2 3 4 5 6
// 3, 5

// 40, 3
// 40명의 병사, 1번부터 시작, 시계방향으로 3번 째 살아 있는 사람이 자살
// ... ~~!!