#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'A'; }

// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
	TrieNode* children[ALPHABETS];
	// 이 노드에서 종료하는 문자열의 번호, 없으면 -1
    int terminal;
    // 이 노드를 루트로 하는 트라이에 가장 먼저 추가된 단어의 번호, -1로 초기화
    int first;
    // 생성자
    TrieNode();
    // ~ : 소멸자
    ~TrieNode();
    // 이 노드를 루트로 하는 트라이에 번호 id인 문자열 key를 추가한다
    void insert(const char* key, int id) {
        // 처음 추가되는 경우(출현 빈도가 높은 경우) first를 우선 갱신
        if (first == -1) first = id;
        // 문자열이 끝났다면 terminal만 바꾸고 종료
        if (*key == 0) 
            terminal = id;
        else {
            int next = toNumber(*key);
            // 해당 자식 노드가 없다면 생성
            if (children[next] == NULL) 
                children[next] = new TrieNode();
            // 해당 자식 노드로 재귀 호출
            children[next]->insert(key+1,id);
        } // first 갱신 -> 재귀 -> 재귀 -> ... -> terminal 갱신 형태!
    }

	// 이 노드를 루트로 하는 트라이에 문자열 key 와 대응되는 노드를 찾는다.
	// 없으면 NULL 을 반환한다.
	TrieNode* find(const char* key) {
		if(*key == 0) return this;
		int next = toNumber(*key);
		if(children[next] == NULL) return NULL;
		// children[next]는 자식 trieNode의 포인터
		// 자식 tridNode struct의 find메서드 호출
		return children[next]->find(key+1);
	}

    // 이 노드까지 타이핑해 왔을 때, 번호 id인 key를 타이핑하기 위해
    // 최소 몇 번의 키를 더 눌러야 하나?
    int type(const char* key, int id) {
        // 문자열 종료 시
        if (*key == 0) return 0;
        // 이 노드에서 추천되는 문자열이 이 문자열이면 탭 누르고 종료
        if (first == id) return 1;
        // 아니면 다음 문자를 타이핑
        int next = toNumber(*key);
        return 1 + children[next]->type(key + 1, id);
    }
};

// 사전을 나타내는 트라이가 주어질 때, 단어 word를 타이핑하는 데
// 몇 번이나 키를 눌러야 하는지 계산
int countKeys(TrieNode* trie, const char* word) {
    // 이 문자열이 사전에 있는지 확인하고, 있다면 번호를 구한다
    // (find는 문자열을 인풋으로 받고 그 문자열에 해당하는 노드를 리턴)
    TrieNode* node = trie->find(word);
    // 사전에 없으면 직접 타이핑할 수밖에 없다
    // 문자열의 길이만큼!
    if (node == NULL || node->terminal == -1) return strlen(word);
    // 탐색하면서 타이핑할 방법을 찾는다
    // 이 문자열은 이미 사전에 있으므로 node의 terminal이 id
    return trie->type(word, node->terminal);
}

// 입력에 주어지는 단어들을 정렬해서 트라이로 변환
TrieNode* readInput(int words) {
    // 단어들을 출현 빈도의 내림차순, 단어의 오름차순으로 정렬
    vector<pair<int,string>> input;
    for(int i = 0; i < words; ++i) {
        char buf[11];
        int freq;
        scanf("%s %d", buf, &freq);
        input.push_back(make_pair(-freq, buf));
    }
    sort(input.begin(), input.end());
    // 이때 앞에 있는 단어일수록 우선순위가 높다
    // 배열의 인덱스를 각 단어의 번호로 쓰자
    TrieNode* trie = new TrieNode();
    for(int i = 0; i < input.size(); ++i)
        trie->insert(input[i].second.c_str(), i);
    // 아무 글자도 입력하지 않으면 자동 완성이 되지 않도록 -1로 초기화
    trie->first = -1;
    return trie;
}