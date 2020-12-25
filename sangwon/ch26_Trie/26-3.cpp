#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

struct TrieNode {
    int type(const char* key, int id) {
        if(*key == 0) return 0;
        if(first == id) return 1;
        int next = toNumber(*key);
        return 1 + children[next]->type(key + 1, id);
    }
};

int countKeys(TrieNode* trie, const char* word) {
    TrieNode* node = trie->find(word);
    if(node == NULL || node->terminal == -1) return strlen(word);
    return trie->type(word, node->terminal)
}