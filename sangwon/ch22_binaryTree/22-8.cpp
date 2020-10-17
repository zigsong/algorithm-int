int n, shifted[50000];
int A[50000];
void solve() {
    Node* candidates = NULL;
    for(int i = 0; i < n; ++i)
        candidates = insert(candidates, new Node(i+1));
    for(int i = n-1; i >= 0; --i){
        int larger = shifted[i];
        Node* k = kth(candidates, i + 1 - larger);
        A[i] = k->key;
        candidates = erase(candidates, k->key);
    }
}