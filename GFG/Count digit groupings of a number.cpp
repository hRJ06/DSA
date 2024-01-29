class Solution{
    private:
    int f(int index,int prev,string &str,vector<vector<int>> &dp,int n) {
        if(index >= n) return 1;
        if(dp[index][prev] != -1) return dp[index][prev];
        int ans = 0, sum = 0;
        for(int i = index; i<n; i++) {
            sum += str[i] - '0';
            if(sum >= prev) {
                ans += f(i + 1,sum,str,dp,n);
            }
        }
        return dp[index][prev] = ans;
    }
	public:
	int TotalCount(string str){
	    // Code here
	    int n = str.size();
	    vector<vector<int>> dp(n,vector<int>(900 + 1,-1));
	    return f(0,0,str,dp,n);
	}

};