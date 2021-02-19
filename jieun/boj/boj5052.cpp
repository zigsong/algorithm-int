//
// Created by songji on 2021/02/19.
//
// 주어진 전화번호가 트라이의 리프 노드가 아니면 false

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10; // 트라이 노드마다 포인터 개수

struct Trie {
    Trie *children[MAX];
    bool terminal;
    bool hasChild;

    Trie() { // 생성자
        fill(children, children+MAX, nullptr);
        terminal = hasChild = false;
    };

    ~Trie() { // 소멸자
        for (int i=0; i<MAX; i++) {
            if (children[i]) delete children[i];
        }
    }

    void insert(const char* key) { // 문자열 key를 현재 노드부터 삽입
        if (*key == '\0') { // 문자열의 끝
            terminal = true;
        } else {
            int next = *key - '0'; // index of next child
            if (!children[next]) {
                children[next] = new Trie;
            }
            hasChild = true;
            children[next]->insert(key + 1);
        }
    }

    bool consistent() {
        // 자식도 있으면서 여기서 끝나는 전화번호도 있다면 일관성 없음
        if (hasChild && terminal) return false;
        // 자식들 중 하나라도 일관성이 없으면 이 노드도 일관성이 없음
        for (int i=0; i<MAX; i++) {
            if (children[i] && !children[i]->consistent()) return false;
        }
        // 일관성 있음
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        Trie* root = new Trie;
        for (int j=0; j<n; j++) {
            char tel[MAX+1]; // 11
            cin >> tel;
            root->insert(tel);
        }
        if (root->consistent()) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
        delete root;
    }
}