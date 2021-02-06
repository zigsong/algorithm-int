//
// Created by songji on 2021/01/12.
//

// 마지막 테케만 안 돌아감. 백준 Segfault 런타임 에러
#include <iostream>
#include <list>

using namespace std;

int main() {
    string s;
    int m;
    cin >> s >> m;
//    list<char> l(s.begin(),s.end()); // 아래와 같은 방법
    list<char> text;
    for (int i=0; i<s.length(); i++) {
        text.push_back(s[i]);
    }

    list<char>::iterator it = text.end();
    for (int i=0; i<m; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (it != text.begin()) {
                it--;
            }
        } else if (cmd == 'D') {
            if (it != text.end()) {
                it++;
            }
        } else if (cmd == 'B') {
            if (it != text.begin()) {
                text.erase(--it);
            }
        } else if (cmd == 'P') {
            char x;
            cin >> x;
            text.insert(it, x);
        }
    }

//    for (char c : text) {
//        cout << c;
//    }

    for (auto it=text.begin(); it != text.end(); it++) {
        cout << *it;
    }

    return 0;
}