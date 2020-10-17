#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool wellMatched(const string& formula) {
  const string opening("({["), closing(")}]");
  // 이미 열린 괄호들을 순서대로 담는 스택
  stack<char> openStack;
  for (int i=0; i<formula.size(); ++i) {
    // 여는 괄호라면 stack에 push
    if (opening.find(formula[i]) != -1) {
      openStack.push(formula[i]);
    } else {
      if (openStack.empty()) return false;
      if (opening.find(openStack.top()) != closing.find(formula[i])) return false;
      openStack.pop();
    }
  }
  return openStack.empty();
}