//
// Created by songji on 2021/02/15.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    map<string, Node*> child;

    void insert(vector<string> v, int idx) { // idx: 현재 개미굴의 층수
        if (idx == v.size()) return;

        string s = v[idx];
        if (child.find(s) != child.end()) { // child에 Node가 있는 경우
            child.find(s)->second->insert(v, idx+1);
        } else {
            Node* node = new Node;
            child.insert({ s, node }); // 없으면 새로 넣어줌
            node->insert(v, idx+1);
        }
    }

    void print(int idx) {
        if (child.empty()) return;
        for (auto it = child.begin(); it != child.end(); it++) {
            for (int i=0; i<idx; i++) cout << "--";
            cout << it->first << "\n";
            it->second->print(idx+1); // dfs로 탐색하며 출력
        }
    }
};

int main() {
    int n;
    cin >> n;
    Node* root = new Node;
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        vector<string> v;
        for (int i=0; i<k; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        root->insert(v, 0); // B, A를 모두 포함하는 가상의 루트 노드 (0층 = 지상층)
    }
    root->print(0);
    return 0;
}