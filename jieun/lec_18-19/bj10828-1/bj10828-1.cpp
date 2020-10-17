#include <iostream>

using namespace std;

struct Stack {
  int data[10000];
  int begin, end;

  Stack() {
    begin = 0;
    end = 0;
  }

  void push(int num) {
    data[end] = num;
    end += 1;
  }

  int pop() {
    if (empty()) return -1;
    else {
      int val = data[end-1];
      end--;
      return val;
    }
  }

  int size() {
    return end - begin;
  }

  bool empty() {
    return size() == 0 ? 1 : 0;
  }

  int top() {
    if (empty()) return -1;
    else return data[end-1];
  }
};

int main() {
  int N;
  cin >> N;

  Stack s;

  while(N--) {
    string cmd;
    cin >> cmd;
    
    if (cmd == "push") {
      int num;
      cin >> num;
      s.push(num);
    } else if (cmd == "pop") {
      cout << s.pop() << endl;
    } else if (cmd == "size") {
      cout << s.size() << endl;
    } else if (cmd == "empty") {
      cout << s.empty() << endl;
    } else if (cmd == "top") {
      cout << s.top() << endl;
    }
  }
}
