class TreeNode:
    def __init__(self, root):
        self.root = root
        self.left = None
        self.right = None
    
    def setLeft(self, left):
        self.left = left
        
    def setRight(self, right):
        self.right = right

    def __str__(self):
        return self.root
        

a = TreeNode("A")
b = TreeNode("B")
c = TreeNode("C")

a.setLeft(b)
a.setRight(c)

print(a)
print(a.left)
print(a.right)


# print(b.node)
# print(a.right)