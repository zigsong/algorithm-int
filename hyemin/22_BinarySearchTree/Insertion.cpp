#include <set>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// shifted[i] = A[i]가 왼쪽으로 몇 칸 움직이는가?
int n, shifted[50000];
int A[50000];
// n, shifted[]를 보고 A[]에 값을 저장한다.
void solve()
{
    // 1~N까지의 숫자를 모두 저장하는 트림
    Node *candidates = NULL;
    for (int i = 0; i < n; ++i)
        candidates = insert(candidates, new Node(i + 1));
    // 뒤에서부터 A[]를 채워나간다
    for (int i = n - 1; i >= 0; --i)
    {
        // 후보 중 이 수보다 큰 수가 Larger개 있다
        int larger = shifted[i];
        Node *k = kth(candidates, i + 1 - larger);
        A[i] = k->key;
        candidate = erase(candidates, k->key);
    }
}