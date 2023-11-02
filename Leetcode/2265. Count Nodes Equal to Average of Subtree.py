# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.ans = 0

    def f(self, root):
        if not root:
            return (0, 0)
        l = self.f(root.left)
        r = self.f(root.right)
        s = l[1] + r[1] + root.val
        n = 1 + l[0] + r[0]
        self.ans += int(s / n) == root.val
        return (n, s)

    def averageOfSubtree(self, root: TreeNode) -> int:
        self.f(root)
        return self.ans
