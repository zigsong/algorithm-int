# **Lecture 26: 트라이**

by | 혜민

pub date | 2020.11.07.Sat

### **트라이**

- 문자열을 다룰 때는 다른 정수, 실수 등의 자료형과 다르게 시간 복잡도가 O(MlogN) (M:문자열의 최대 길이, N:원소의 갯수)
- 이와 같은 시간 복잡도 문제를 해결하기 위해 고안된 자료 구조가 **트라이(trie)**

<img src='./lecture26.assets/trie.png'>

트라이의 중요한 속성
- 한 노드까지 따라가는 경로에서 만나는 글자들을 모으면 해당 노드에 대응되는 접두사 -> 대응되는 문자열을 저장할 필요 없음
- 트라이의 한 노드는 자손 노드를 가리키는 `포인터 목록 children[ALPHABET]` 종료 노드인지를 가리키는 `terminal` 변수로 구성

#### 트라이의 구현
  
[코드 26.1](../hyemin/26_Trie/Trie.cpp)
```c++
// 트라이의 노드를 표현하는 객체의 선언

// 알파벳 대문자를 저장하는 경우 각 노드는 26개의 자손을 가질 수 있다
const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'A'; }

// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
	TrieNode* children[ALPHABETS];
	// 이 노드가 종료 노드인가?
	bool terminal;

	// 생성자
	// : (콜론)을 쓰는 이유는 초기화 리스트를 사용했기 때문
	// 초기화 리스트 : 생성자가 호출될 때 객체의 생성과 초기화가 한 번에 이루어짐
	// 생성자 함수 내에서 초기화 : 객체가 생성되어, default생성자로 초기화된 상태에서 다시 한 번 할당
	TrieNode() : terminal(false) {
		memset(children, 0, sizeof(children));
	}

	// 소멸자 : 메모리 지워준다
	~TrieNode() {
		for(int i = 0; i < ALPHABETS; i++)
			if(children[i])
				delete children[i];
	}

	// 이 노드를 루트로 하는 트라이에 문자열 key 를 추가한다.
	void insert(const char* key) {
		// 문자열이 끝나면 terminal 만 참으로 바꾸고 종료
		if(*key == 0)
			terminal = true;
		else {
			int next = toNumber(*key);
			// 해당 자식 노드가 없다면 생성한다
			if(children[next] == NULL)
				children[next] = new TrieNode();
			// 해당 자식 노드로 재귀호출
			children[next]->insert(key + 1);
		}
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
};
```
- find()와 insert()모두 문자열의 길이만큼 재귀 호출을 수행하므로 O(M)
