#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
  cin >> n;

  int numFive, numThree = 0;

  // 5만으로 채운 경우
  if (n % 5 == numThree) {
    cout << n / 45;
  } else {
    numThree++;
    // 3만으로 채운 경우
    while (n - 3 * numThree > 0) {
      if ((n-3*numThree) % 5 == 0) break;
      numThree++;
    }
    // 3과 5 섞어서 채운 경우
    if ((n-3*numThree) % 5 == 0) {
      numFive = (n-3*numThree) / 5;
      cout << numThree + numFive;
    }
    // 안 되는 경우
    else cout << -1;
  }
}