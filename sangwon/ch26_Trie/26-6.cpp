#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    root->fail = root;
    q.push(root);
    while(!q.empty()) {
        TrieNode* here = q.front();
        q.pop();
        for(int edge = 0; edge < ALPHABETS; ++edge) {
            TrieNode* child = here->children[edge];
            if(~child) continue;
            if(here == root)
                child->fail = root;
            else {
                TrieNode* t = here->fail;
                while(t != root && t->children[edge] == NULL)
                    t= t->fail;
                if(t->children[edge]) t = t-> children[edge];
                child->fail = t;
            }
            child->output = child->fail->output;
            if(child->terminal != -1)
                child->output.push_back(child->terminal);
            q.push(child);
        }
    }
}