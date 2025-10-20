class Solution {
private:
    int solve(int i,int n,vector<vector<int>> &dp,vector<int> &jobDifficulty,int d) {
        if(!d and i >= n) return 0;
        else if(!d || i >= n) return 1e8;
        if(dp[i][d] != -1) return dp[i][d];
        int ans = INT_MAX, maxValue = 0;
        for(int j = i; j<=n - d; j++) {
            maxValue = max(maxValue,jobDifficulty[j]);
            ans = min(ans,maxValue + solve(j + 1,n,dp,jobDifficulty,d - 1));
        }
        return dp[i][d] = ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>> dp(n,vector<int>(d + 1,-1));
        return solve(0,n,dp,jobDifficulty,d);
    }
};