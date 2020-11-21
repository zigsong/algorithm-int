struct TrieNode { 
    TrieNode* children[ALPHABETS];
    int terminal;
    int first;
    TrieNode();
    ~TrieNode();
    void insert(const char* key, int id) {
        if(first == -1) first = id;
        if(*key == 0)
            terminal = id;
        else {
            int next = toNumber(*key);
            if(children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key+1, id);
        }
    }
    int type(const char* key, int id);
};
