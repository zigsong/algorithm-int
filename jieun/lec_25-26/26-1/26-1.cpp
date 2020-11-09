#include <iostream>
#include <vector>

using namespace std;

const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'A'; }

// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
  TrieNode* children[ALPHABETS];  
  // 이 노드가 종료 노드인가?
  bool terminal;
  TrieNode() : terminal(false) {
    memset(children, 0, sizeof(children));
  }
  ~TrieNode() {
    for (int i=0; i<ALPHABETS; ++i) {
      if (children[i]) delete children[i];
    }
  }

  // 문자열 포인터를 사용하여 key+1 => 다음 알파벳으로 이동
  void insert(const char* key) {
    if (*key == 0) terminal = true;
    else {
      int next = toNumber(*key);
      if (children[next] == NULL) children[next] = new TrieNode();
      children[next]->insert(key+1);
    }
  }

  TrieNode* find(const char* key) {
    if (*key == 0) return this;
    int next = toNumber(*key);
    if (children[next] == NULL) return NULL;
    return children[next]->find(key+1);
  }
};