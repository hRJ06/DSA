class Solution:
    def f(self,i,j,X,Y,dp):
        if i < 0 or j < 0:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        if X[i] != Y[j]:
            dp[i][j] = max(self.f(i - 1,j,X,Y,dp),self.f(i,j - 1,X,Y,dp))
        else:
            dp[i][j] = 1 + self.f(i - 1,j - 1,X,Y,dp)
        return dp[i][j]
            
    #Function to find length of shortest common supersequence of two strings.
    def shortestCommonSupersequence(self, X, Y, m, n):
        dp = [[-1 for _ in range(n)] for _ in range(m)]
        lcs = self.f(m - 1,n - 1,X,Y,dp)
        return m + n - lcs
