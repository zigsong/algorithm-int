#include <iostream>
#include <cstdio>
using namespace std;

struct Tree
{
    int left = 0;
    int right = 0;
};

Tree tree[100001];

void postOrder(int node)
{
    if (tree[node].left != 0)
    {
        postOrder(tree[node].left);
    }
    if (tree[node].right != 0)
    {
        postOrder(tree[node].right);
    }
    printf("%d\n", node);
}

int main()
{
    int root;
    int value;
    scanf_s("%d", &root);
    while (scanf_s("%d", &value) != EOF)
    {
        int node = root;
        while (true)
        {
            if (node < value)
            {
                if (tree[node].right != 0)
                {
                    node = tree[node].right;
                }
                else
                {
                    tree[node].right = value;
                    break;
                }
            }
            else
            {
                if (tree[node].left != 0)
                {
                    node = tree[node].left;
                }
                else
                {
                    tree[node].left = value;
                    break;
                }
            }
        }
    }
    postOrder(root);
    return 0;
}
