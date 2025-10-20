class Solution:
    def __init__(self):
        self.MOD = 10**9 + 7
        self.dir = [-1, 0, 1, 0, -1]
    def f(self, i, j, M, m, n, dp):
        if i < 0 or i == m or j < 0 or j == n:
            return 1
        if not M:
            return 0
        if dp[i][j][M] != -1:
            return dp[i][j][M]
        ans = 0
        for k in range(4):
            ni, nj = i + self.dir[k], j + self.dir[k + 1]
            ans = (ans + self.f(ni, nj, M - 1, m, n, dp)) % self.MOD
        dp[i][j][M] = ans
        return dp[i][j][M]
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        dp = [[[(-1) for _ in range(maxMove + 1)] for _ in range(n)] for _ in range(m)]
        return self.f(startRow, startColumn, maxMove, m, n, dp)