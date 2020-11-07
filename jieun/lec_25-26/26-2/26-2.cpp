#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'A'; }


struct TrieNode {
  TrieNode* children[ALPHABETS];
  int terminal;
  // -1로 초기화

  int first;
  TrieNode();
  ~TrieNode();

  // 26-5
  // 실패 연결: 이 노드에서 매칭이 실패했을 때 이 곳으로 가서 게속한다.
  TrieNode* fail;
  // 출력 문자열 목록: 이 노드가 방문되었을 때 등장하는 바늘 문자열들의 번호
  vector<int> output;

  TrieNode* find(const char* key) {
    if (*key == 0) return this;
    int next = toNumber(*key);
    if (children[next] == NULL) return NULL;
    return children[next]->find(key+1);
  }

  void insert(const char* key, int id) {
    if (first == -1) first = id;
    // 문자열이 끝났다면 terminal만 바꾸고 종료
    if (*key == 0) terminal = id;
    else {
      int next = toNumber(*key);
      if (children[next] == NULL) children[next] = new TrieNode();
      children[next]->insert(key+1, id);
    }
  }
  
  // 이 노드까지 타이핑해 왔을 때, 번호 id인 key를 타이핑하기 위해
  // 최소 몇 번의 키를 더 눌러야 하나?
  int type(const char* key, int id) {
    if (*key == 0) return 0;
    // 이 노드에서 추천되는 문자열이 이 문자열이면 탭 누르고 종료
    if (first == id) return 1;
    // 아니면 다음 문자를 타이핑
    int next = toNumber(*key);
    return 1 + children[next]->type(key+1, id);
  }
};

int countKeys(TrieNode* trie, const char* word) {
  TrieNode* node = trie->find(word);
  if (node == NULL || node->terminal == -1) return strlen(word);
  return trie->type(word, node->terminal);
}

TrieNode* readInput(int words) {
  vector<pair<int, string> > input;
  for (int i=0; i<words; ++i) {
    char buf[11];
    int freq;
    scanf("%s %d", buf, &freq);
    // sort할 때 우선순위가 높은 게 앞으로 가게 하기 위해
    input.push_back(make_pair(-freq, buf));
  }
  sort(input.begin(), input.end());

  // 배열의 인덱스를 각 단어의 번호로 사용
  TrieNode* trie = new TrieNode();
  for (int i=0; i<input.size(); ++i) {
    trie->insert(input[i].second.c_str(), i);
  }
  // 트라이 생성 후 루트의 first 멤버를 -1로 초기화
  trie->first = -1;
  return trie;


}

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
      if (child->terminal != -1) {
        child->output.push_back(child->terminal);
      }
      q.push(child);
    }
  }
}

vector<pair<int, int> > ahoCorasick(const string& s, TrieNode* root) {
  vector<pair<int, int> > ret;
  TrieNode* state = root;
  for (int i=0; i<s.size(); ++i) {
    int chr = toNumber(s[i]);
    while (state != root && state->children[chr] == NULL) {
      state = state->fail;
    }
    if (state->children[chr]) state = state->children[chr];
    for (int j=0; j<state->output.size(); ++j) {
      ret.push_back(make_pair(i, state->output[j]));
    }
  }
  return ret;
}