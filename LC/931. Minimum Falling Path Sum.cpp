from typing import List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = [[-1 for col in range(n)] for i in range(m)]
        for i in range(n):
            dp[m - 1][i] = matrix[m - 1][i]
        for i in range(m - 2, -1, -1):
            for j in range(n):
                a = dp[i + 1][j - 1] if j > 0 else float('inf')
                b = dp[i + 1][j]
                c = dp[i + 1][j + 1] if j < n - 1 else float('inf')
                dp[i][j] = matrix[i][j] + min(a, b, c)
        ans = min(dp[0])
        return ans
