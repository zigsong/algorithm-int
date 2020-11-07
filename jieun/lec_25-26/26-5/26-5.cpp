#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int ALPHABETS = 26;
const int SIZE = 30;
int toNumber(char ch) { return ch - 'A'; }

struct TrieNode {
  TrieNode* node[SIZE];  
  bool terminal;

  TrieNode* children[ALPHABETS];  

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

  // 26-5 추가
  int terminal;
  // 실패 연결: 이 노드에서 매칭이 실패했을 때 이 곳으로 가서 게속한다.
  TrieNode* fail;
  // 출력 문자열 목록: 이 노드가 방문되었을 때 등장하는 바늘 문자열들의 번호
  vector<int> output;
};

void computeFailFunc(TrieNode* root) {
  queue<TrieNode*> q;
  root->fail = root;
  q.push(root);

  while(!q.empty()) {
    TrieNode* here = q.front();
    q.pop();

    for (int edge=0; edge<ALPHABETS; ++edge) {
      TrieNode* child = here->children[edge];
      if(!child) continue;
      // 1레벨 노드의 실패 연결은 항상 루트
      if (here == root) child->fail = root;
      else {
        TrieNode* t = here->fail;
        while (t != root && t->children[edge] == NULL) {
          t = t->fail;
        }
        if (t->children[edge]) t = t->children[edge];
        child->fail = t;
      }

      // 출력 문자열 목록
      child->output = child->fail->output;
      if (child->terminal != -1) child->output.push_back(child->terminal);
      q.push(child);
    }
  }
}

vector<pair<int, int> > ahoCorasik(const string& s, TrieNode* root) {
  vector<pair<int, int> > ret;
  TrieNode* state = root;
  
  for (int i=0; i<s.size(); ++i) {
    int chr = toNumber(s[i]);
    while(state != root && state->children[chr] == NULL) {
      state = state->fail;
    }
    if (state->children[chr]) state = state->children[chr];
    for (int j=0; j<state->output.size(); ++j) {
      ret.push_back(make_pair(i, state->output[j]));
    }
  }
  return ret;
}