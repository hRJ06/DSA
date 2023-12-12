class Solution:

	def countStrings(self,n):
    	# code here
    	dp = [0 for _ in range(n + 1)]
    	dp[0] = 1
    	dp[1] = 2
    	MOD = 10**9 + 7
    	for i in range(2,n + 1):
    	    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD
    	return dp[n]
