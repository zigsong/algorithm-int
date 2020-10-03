#include <iostream>
#include <vector>

using namespace std;

void printPicked(vector<int>& picked) {
  for (int i: picked) 
    cout << i << endl;
}

void pick(int n, vector<int>& picked, int toPick) {
  if(toPick == 0) { // base case: 다 뽑았으면 return
    printPicked(picked);
    return;
  }
  int smallest = picked.empty() ? 0 : picked.back() + 1; // ex) 2개 뽑았다면 3,4번만 (n=4) 뽑으면 됨

  for(int next=smallest; next < n; ++next) {
    picked.push_back(next); // 1. 한번 실험 해주고
    pick(n, picked, toPick-1); // 2. 재귀 호출 
    picked.pop_back(); // 3. 실험 내역 취소 (이전으로 돌아가기)
  }
}

int main() {
  vector<int> vect{};
  pick(4, vect, 2);
}