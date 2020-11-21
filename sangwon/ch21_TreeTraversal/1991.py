# 트리 순회

# 전위 순회: 루트 왼쪽 오른쪽
# 중위 순회: 왼쪽 루트 오른쪽
# 후위 순회: 왼쪽 오른쪽 루트

import sys

class TreeNode:
    def __init__(self, root, left=None, right=None):
        self.root = root
        self.left = left
        self.right = right
    
    def setLeft(self, left):
        self.left = left
        
    def setRight(self, right):
        self.right = right

    def __str__(self):
        return self.root

# class Tree:
#     def __init__(self, RootNode):
#         self.RootNode = RootNode

def preorder(RootNode):
    if RootNode.root == None:
        return
    print(RootNode.root, end="")
    preorder(RootNode.left)
    preorder(RootNode.right)

def inorder(RootNode):
    if RootNode.root == None:
        return
    inorder(RootNode.left)
    print(RootNode.root, end="")
    inorder(RootNode.right)

def postorder(RootNode):
    if RootNode.root == None:
        return
    postorder(RootNode.left)
    postorder(RootNode.right)
    print(RootNode.root, end="")

# preorder 루 왼 오
# Root 를 입력으로 받으면
# root 출력, left 를 root로 다시 호출, right 를 root 로 호출


n = int(sys.stdin.readline().rstrip())
nodes = {}
root_node = None
left_node = None
right_node = None

for i in range(n):
    root, left, right = sys.stdin.readline().rstrip().split(" ")

    if left == ".":
        left = None
    if right == ".":
        right = None

    # root 가 이전 left 나 right 로 이미 만들어졌다면
    if root in nodes.keys():
        root_node = nodes[root]

    # 이전에 루트에 해당하는 node 가 없으면
    else:
        root_node = TreeNode(root)
        nodes[root] = root_node

    left_node = TreeNode(left)
    right_node = TreeNode(right)

    # 딕셔너리에 저장
    nodes[left] = left_node
    nodes[right] = right_node

    root_node.setLeft(left_node)
    root_node.setRight(right_node)

preorder(nodes["A"])
print()
inorder(nodes["A"])
print()
postorder(nodes["A"])