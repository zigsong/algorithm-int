#include <iostream>

using namespace std;

string reverse(string::iterator& it) {
  char head = *it;
  ++it;
  if (head == 'b' || head == 'w')
    return string(1, head); // 어떤 function인지?
  string upperLeft = reverse(it);
  string upperRight = reverse(it);
  string lowerLeft = reverse(it);
  string lowerRight = reverse(it);

  return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}