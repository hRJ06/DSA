class Solution:
    #Function to check if two trees are identical.
    def isIdentical(self,root1, root2):
        # Code here
        if not root1 and not root2:
            return True
        elif root1 and not root2:
            return False
        elif not root1 and root2:
            return False
        else:
            return root1.data == root2.data and self.isIdentical(root1.left,root2.left) and self.isIdentical(root1.right,root2.right)