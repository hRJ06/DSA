class Solution:
    def __init__(self):
        self.head = None
        self.prev = None
    def inorder(self,root):
        if root is None:
            return
        self.inorder(root.left)
        if self.head is None:
            self.head = root
        else:
            root.left = self.prev
            self.prev.right = root
        self.prev = root
        self.inorder(root.right)
    #Function to convert binary tree into circular doubly linked list.
    def bTreeToClist(self, root):
        #Your code here
        self.inorder(root)
        # Circular
        self.head.left = self.prev
        self.prev.right = self.head
        return self.head
