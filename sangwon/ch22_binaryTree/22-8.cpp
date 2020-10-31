// 삽입 정렬 뒤집기 문제를 해결하는 아록리즘

//shifted[i]=A[i] 가 왼쪽으로 몇 칸 움직이는가
int n, shifted[50000];
int A[50000];
// n, shifted[] 를 보고 A[]에 값을 저장한다.
void solve() {
    // 1 ~ N 까지의 숫자를 모두 저장하는 트립을 만든다.
    Node* candidates = NULL;
    for(int i = 0; i < n; ++i)
        candidates = insert(candidates, new Node(i+1));
    // 뒤에서부터 A[]를 채워나간다
    for(int i = n-1; i >= 0; --i){
        // 후보 중 이 수보다 큰 수가 larger 개 있다.
        int larger = shifted[i];
        Node* k = kth(candidates, i + 1 - larger);
        A[i] = k->key;
        candidates = erase(candidates, k->key);
    }
}