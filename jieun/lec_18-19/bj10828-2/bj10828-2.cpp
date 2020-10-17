#include <iostream>
#include <stack>

using namespace std;

int main() {
  int N;
  cin >> N;

  stack<int> s;

  while(N--) {
    string cmd;
    cin >> cmd;

    if (cmd == "push") {
      int num;
      cin >> num;
      s.push(num);
    } else if (cmd == "pop") {
      if (s.empty()) cout << -1 << endl;
      else {
        cout << s.top() << endl;
        s.pop();
      }
    } else if (cmd == "size") {
      cout << s.size() << endl;
    } else if (cmd == "empty") {
      cout << s.empty() << endl;
    } else if (cmd == "top") {
      if (s.empty()) cout << -1 << endl;
      else cout << s.top() << endl;
    }
  }
}