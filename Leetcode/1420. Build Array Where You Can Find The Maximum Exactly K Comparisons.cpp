class Solution {
private:
    int MOD = 1e9 + 7;
    int dp[51][51][101];
    int solve(int index,int sc,int maxi,int n,int m,int k) {
        if(index == n) {
            if(sc == k) return 1;
            return 0;
        }
        if(dp[index][sc][maxi] != -1) return dp[index][sc][maxi];
        int ans = 0;
        for(int i = 1; i<=m; i++) {
            if(i > maxi) 
                ans = (ans + solve(index + 1,sc + 1,i,n,m,k)) % MOD;
            else
                ans = (ans + solve(index + 1,sc,maxi,n,m,k)) % MOD;
        }
        return dp[index][sc][maxi] = ans % MOD;
    }
public:
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,m,k);
    }
};