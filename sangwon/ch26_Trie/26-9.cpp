void computeTransition(TrieNode* here, int& nodeCounter) {
    here->no = nodeCounter++;
    for(int chr = 0; chr < ALPHABETS; ++chr) {
        TrieNode* next = here;
        while(next != next->fail && next->children[chr] == NULL)
            next = next->fail;
        if(next->children[chr]) next = next->children[chr];
        here->next[chr] = next;
        if(here->children[chr])
            computeTransition(here->children[chr], nodeCounter);
    }
}