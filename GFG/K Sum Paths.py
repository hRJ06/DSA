class Solution:
    def __init__(self):
        self.Map = {}
        self.ans = 0
        self.MOD = int(1e9 + 7)

    def f(self, root, cur, tar):
        if not root:
            return
        if (cur + root.data) == tar:
            self.ans = (self.ans + 1) % self.MOD
        self.ans = (self.ans + self.Map.get((cur + root.data) - tar, 0)) % self.MOD
        self.Map[cur + root.data] = self.Map.get(cur + root.data, 0) + 1
        self.f(root.left, cur + root.data, tar)
        self.f(root.right, cur + root.data, tar)
        self.Map[cur + root.data] -= 1

    def sumK(self, root, k):
        self.f(root, 0, k)
        return self.ans