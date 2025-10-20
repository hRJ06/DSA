class Solution:
    def __init__(self):
        self.ans = []
    def f(self,root):
        if not root:
            return
        self.f(root.left)
        self.ans.append(root.val)
        self.f(root.right)
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.f(root)
        return self.ans
        

        