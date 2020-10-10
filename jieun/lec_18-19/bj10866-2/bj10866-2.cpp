#include <iostream>
#include <deque>

using namespace std;

int main() {
  int N;
  cin >> N;

  deque<int> d;

  while(N--) {
    string cmd;
    cin >> cmd;

    if (cmd == "push_front") {
      int num;
      cin >> num;
      d.push_front(num);
    } else if (cmd == "push_back") {
      int num;
      cin >> num;
      d.push_back(num);
    } else if (cmd == "pop_front") {
      if (d.empty()) cout << -1 << endl;
      else {
        cout << d.front() << endl;
        d.pop_front();
      }
    } else if (cmd == "pop_back") {
      if (d.empty()) cout << -1 << endl;
      else {
        cout << d.back() << endl;
        d.pop_back();
      }
    } else if (cmd == "size") {
      cout << d.size() << endl;
    } else if (cmd == "empty") {
      cout << d.empty() << endl;
    } else if (cmd == "front") {
      if (d.empty()) cout << -1 << endl;
      else cout << d.front() << endl;
    } else if (cmd == "back") {
      if (d.empty()) cout << -1 << endl;
      else cout << d.back() << endl;
    }
  }
}