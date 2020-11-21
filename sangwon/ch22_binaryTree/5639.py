# 5639 이진 트리
# 이것도 devide and conquer 써야 잘 풀린다

# 노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다.
# 노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다.
# 왼쪽, 오른쪽 서브트리도 이진 검색 트리이다.

# 입력: 전위 순회한 결과
# 출력: 후위 순회한 결과
# 트리를 구성, 후위순회

import sys

class TreeNode:
    def __init__(self, root):
        self.root = root
        self.left = None
        self.right = None
    
    def setLeft(self, left):
        self.left = left
    
    def setRight(self, right):
        self.right = right

# 루트에서부터 내려오고
# 크면 오른쪽, 작으면 왼쪽
# None이면 그 자리에 멈춤
def setBinaryTree(prevNode, curNode):
    if curNode.root < prevNode.root:
        if prevNode.left == None:
            prevNode.setLeft(curNode)
        else:
            setBinaryTree(prevNode.left, curNode)
            
    elif curNode.root > prevNode.root:
        if prevNode.right == None:
            prevNode.setRight(curNode)
        else:
            setBinaryTree(prevNode.right, curNode)

def postorder(RootNode):
    if RootNode == None:
        return
    postorder(RootNode.left)
    postorder(RootNode.right)
    print(RootNode.root)

root = TreeNode(int(sys.stdin.readline().rstrip()))

for i in range(10000):
    num = sys.stdin.readline().rstrip()
    if num == "":
        break
    num = int(num)
    node = TreeNode(num)

    setBinaryTree(root, node) # root 와 비교

postorder(root)

# for key, value in nodes.items():
#     print("num", key)
#     print("root", value.root)
#     print("left", value.left)
#     print("right", value.right)
#     print()
# 50
# 30
# 24
# 5
# 28
# 45
# 98
# 52
# 60