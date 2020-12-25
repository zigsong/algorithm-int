#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

struct TrieNode {
    int terminal;
    TrieNode* fail;
    vector<int> output;
    
}