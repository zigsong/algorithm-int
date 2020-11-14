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
    
    

