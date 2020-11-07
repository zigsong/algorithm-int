#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int SIZE = 30;
int toNumber(char ch) { return ch - 'A'; }

struct TrieNode {
  TrieNode* node[SIZE];  
  bool terminal;

  TrieNode() : terminal(false) {
    memset(node, 0, sizeof(node));
  }
  ~TrieNode() {
    for (int i=0; i<SIZE; ++i) {
      if (node[i]) delete node[i];
    }
  }

  void insert(const char* key) {
    if (*key == 0) terminal = true;
    else {
      int next = toNumber(*key);
      if (node[next] == NULL) node[next] = new TrieNode();
      node[next]->insert(key+1);
    }
  }

  TrieNode* find(const char* key) {
    if (*key == 0) return this;
    int next = toNumber(*key);
    if (node[next] == NULL) return NULL;
    return node[next]->find(key+1);
  }
};

int n, m;
int main() {
  TrieNode root;
  scanf("%d %d", n, m);
  char word[501];
  for (int i=0; i<n; i++) {
    scanf("%s", &word);
    root.insert(word);
  }

  int cnt = 0;
  for (int i=0; i<m; i++) {
    char input[501];
    scanf("%s", &input);
    if (root.find(input)) cnt++;
  }

  printf("%d", cnt);
}