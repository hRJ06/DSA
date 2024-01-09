# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def f(self,root,lS):
        if not root:
            return
        if not root.left and not root.right:
            lS.append(root.val)
        self.f(root.left,lS)
        self.f(root.right,lS)
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        lS1, lS2 = [], []
        self.f(root1,lS1)
        self.f(root2,lS2)
        return lS1 == lS2

        