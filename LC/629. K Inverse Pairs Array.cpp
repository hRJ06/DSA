class Solution {
private:
    int MOD = 1e9 + 7;
    int f(int n,int k,vector<vector<int>> &dp) {
        if(!n) return 0;
        if(!k) return 1;
        if(dp[n][k] != -1) return dp[n][k];
        int ans = 0;
        for(int i = 0; i<=min(k,n - 1); i++) {
            ans = (ans + f(n - 1,k - i,dp) % MOD) % MOD;
        }
        return dp[n][k] = ans;
    }
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1,vector<int>(k + 1,-1));
        return f(n,k,dp);
    }
};