const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'A'; }
struct TrieNode {
    TrieNode* children[ALPHABETS];
    bool terminal;
    TrieNode() : terminal(false) {
        memset(children, 0 , sizeOf(children));
    }
    ~TrieNode() {
        for(int i = 0; i < ALPHABETS; ++i)
            if(children[i])
                delete children[i];
    }
    void insert(const char* key) {
        if(*key == 0)
            terminal = true;
        else {
            int next = toNumber(*key);
            if(children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key + 1);
        }
    }
    TrieNode* find(const char* key) {
        if(*key == 0) return this;
        int next = toNumber(*key);
        if(children[next] == NULL) return NULL;
        return children[next]->find(key+1);
    }
};