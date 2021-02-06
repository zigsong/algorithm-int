class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        
    def __str__(self) -> str:
        return str(self.data)
    
class Tree:
    def __init__(self, node):
        self.root = node
        
    def inorderAdd(self, node, left, right):
        if self.root == None:
            self.root = node
        node.left = left
        node.right = right
        
    
    def preorderTraversal(self, node):
        print(node, end='')
        if node.left != None: self.preorderTraversal(node.left)
        if node.right != None: self.preorderTraversal(node.right)
        
    def inorderTraversal(self, node):
        if node.left != None: self.inorderTraversal(node.left)
        print(node, end='')
        if node.right != None: self.inorderTraversal(node.right)
        
    def postorderTraversal(self, node):
        if node.left != None: self.inorderTraversal(node.left)
        if node.right != None: self.inorderTraversal(node.right)
        print(node, end='')
    
Tree(Node(1))