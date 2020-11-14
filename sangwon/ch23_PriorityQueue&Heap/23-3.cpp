// 23.3 변화하는 중간 값 문제를 트립을 사용해 풀기

// rng 가 생성하는 첫 n개의 난수를 수열에 추가하며 중간값을 구한다.
int runningMedian(int n, RNG rng) {
    Node* root = NULL;
    int ret = 0;
    for(int cnt = 1; cnt <= n; ++cnt) {
        root = insert(root, new Node(rng.next()));
        int median = kth(root, (cnt + 1) / 2)->key;
        ret = (ret + median) % 20090711;
    }
    return ret;
}