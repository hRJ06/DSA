class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	vector<long long int> dp(n + 1);
    	dp[0] = 1;
    	for(auto &i: {3,5,10})
    	    for(int j = i; j<=n; j++) 
    	        dp[j] += dp[j - i];
    	return dp[n];
    	
    }
};