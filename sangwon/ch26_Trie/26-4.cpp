TrieNode* readInput(int words) {
    vector<pair<int, string> > input;
    for(int i = 0; i < words; ++i) {
        char buf[11];
        int freeq;
        scanf("%s %d", buf, &freq);
        input.push_back(make_pair(-freq, buf));
    }
    sort(input.begin(), input.end());
    TrieNode* trie = new TrieNode();
    for(int i = 0; i < input.size(); ++i)
        trie->insert(input[i].second.c_str(), i);
    trie->first = -1;
    return trie;
}