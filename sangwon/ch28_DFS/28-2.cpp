// 28.2 고대어 사전 문제의 그래프를 생성

// 알파벳의 각 글자에 대한 읹버 행렬 표현
// 간선(i,j)는 알파벳 i가 j보다 앞에 와야 함을 나타낸다.
vector<vector<int> > adj;
// 주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다.
void makeGraph(const vector<string>& words) {
    adj = vector<vector<int> >(26, vector<int>(26, 0));
    for(int j = 1; j < words.size(); ++j) {
        int i = j - 1, len = min(words[i].size(), words[j].size());
        // word[i]가 word[j] 앞에 오는 이유를 찾는다.
        for(int k = 0; k < len; ++k) 
            if(words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] = 'a';
                adj[a][b] = 1;
                break;
            }
    }
}