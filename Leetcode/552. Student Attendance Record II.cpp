class Solution {
private:
    int MOD = 1e9 + 7;
    int f(int n,int abs,int late,vector<vector<vector<int>>> &dp) {
        if(abs >= 2 || late >= 3) return 0;
        if(!n) return 1;
        if(dp[n][abs][late] != -1) return dp[n][abs][late];
        int A = f(n - 1,abs + 1,0,dp) % MOD;
        int L = f(n - 1,abs,late + 1,dp) % MOD;
        int P = f(n - 1,abs,0,dp) % MOD;
        int ans = ((A + L) % MOD + P) % MOD;
        return dp[n][abs][late] = ans;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(n,0,0,dp);
    }
};