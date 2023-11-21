class Solution:
    def f(self, root1, root2):
        if not root1 and not root2:
            return True
        if not root1 or not root2:
            return False
        a = self.f(root1.left, root2.right)
        b = self.f(root1.right, root2.left)
        return root1.data == root2.data and a and b

    def isSymmetric(self, root):
        if not root:
            return True
        return self.f(root.left, root.right)
