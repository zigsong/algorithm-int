#include <iostream>

using namespace std;

void asterisk(int x, int y, int size) {
  if ((x/size)%3==1 && (y/size)%3==1) cout << " ";
  else {
    if (size/3 == 0) cout << "*"; // size == 1이 되었을 때 
    else asterisk(x, y, size/3);
  }
}

int main() {
  int num;
  cin >> num;
  
  for (int i=0; i<num; i++) {
    for (int j=0; j<num; j++) {
      asterisk(i, j, num);
    }
    cout << "\n";
  }
  
  return 0;
}