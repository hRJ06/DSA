# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import Queue
class Solution:
    def f(self, Map, root):
        if not root:
            return
        if root.val not in Map:
            Map[root.val] = []
        if root.left:
            Map[root.val].append(root.left.val)
            if root.left.val not in Map:
                Map[root.left.val] = []
            Map[root.left.val].append(root.val)
            self.f(Map, root.left)
        if root.right:
            Map[root.val].append(root.right.val)
            if root.right.val not in Map:
                Map[root.right.val] = []
            Map[root.right.val].append(root.val)
            self.f(Map, root.right)

    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        Map = {}
        Infected = set()
        self.f(Map, root)
        ans = 0
        q = Queue()
        q.put(start)
        while not q.empty():
            n = q.qsize()
            while n:
                top = q.get()
                Infected.add(top)
                for neighbour in Map[top]:
                    if neighbour not in Infected:
                        q.put(neighbour)
                n -= 1 
            ans += 1
        return ans - 1