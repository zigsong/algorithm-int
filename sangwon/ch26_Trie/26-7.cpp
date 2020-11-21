vector<pair<int, int> > ahoCorasick(const string& s, TrieNode* root) {
    vector<pair<int,int> > ret;
    TrieNode* state = root;
    for(int i = 0; i < s.size(); ++i) {
        int chr = toNumber(s[i]);
        while(state != root && state->children[shr] == NULL)
            state = state->fail;
        if(state->children[chr]) state = state->children[chr];
        for(int j = 0; j < state->output.size(); ++j)
            ret.push_back(make_pair(i, state->output[j]));
    }
    return ret;
}