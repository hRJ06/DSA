class Solution:
    def __init__(self):
        self.__cS = 0
        self.__mS = 0
        self.__cN = 0
        self.__ans = []
    def __dfs(self,root):
        if not root:
            return
        self.__dfs(root.left)
        if(root.val == self.__cN):
            self.__cS += 1
        else:
            self.__cS = 1
            self.__cN = root.val
        if self.__cS > self.__mS:
            self.__ans = []
            self.__mS = self.__cS
        if self.__cS == self.__mS:
            self.__ans.append(root.val)
        self.__dfs(root.right)
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.__dfs(root)
        return self.__ans
        