#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> slice(const vector<int> &v, int a, int b)
{
    return vector<int>(v.begin() + a, v.begin() + b);
}
// 트리의 전위탐색 결과와 중위탐색 결과가 주어질 때 후위탐색 결과 출력
void printPostOrder(const vector<int> &preorder, const vector<int> &inorder)
{
    // 트리에 포함된 노드의 수
    const int N = preorder.size();
    // 기저 사례 : 텅 빈 트리면 종료
    if (preorder.empty())
        return;
    // 이 트리의 루트는 전위 탐색 결과로부터 알 수 있음
    const int root = preorder[0];
    // 이 트리의 왼쪽 서브트리의 크기는 중위 탐색 결과에서 루트의 위치를 통해 알 수 있음
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    // 오른쪽 서브트리의 크기는 N에서 왼쪽 서브트리와 루트를 빼면 알 수 있음
    const int R = N - L - 1;
    // 왼쪽과 오른쪽 서브트리의 순회 결과 출력
    printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
    // 후위 순회이므로 루트 마지막으로 출력
    cout << root << ' ';
}