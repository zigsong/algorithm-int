const int MOD = 10007;
int cache[101][1001];

int count(int length, TrieNode* state) {
    if(state->output.size()) return 0;
    if(length == 0) return 1;
    int& ret = cache[length][state->no];
    if(ret != -1) return ret;
    ret = 0;
    for(int letter = 0; letter < ALPHABETS; ++letter) {
        ret += count(length-1, state->next[letter]);
        ret %= MOD;
    }
    return ret;
}