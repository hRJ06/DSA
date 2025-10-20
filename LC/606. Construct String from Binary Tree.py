class Solution:
    def __init__(self):
        self.ans = ""

    def f(self, root):
        if root is None:
            return
        self.ans += str(root.val)
        if root.left or root.right:
            self.ans += "("
            self.f(root.left)
            self.ans += ")"
        if root.right:
            self.ans += "("
            self.f(root.right)
            self.ans += ")"

    def tree2str(self, root: TreeNode) -> str:
        self.f(root)
        return self.ans
        