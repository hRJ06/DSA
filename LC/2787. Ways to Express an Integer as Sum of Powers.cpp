typedef long long ll;
class Solution {
private:
    int MOD = 1e9 + 7;
    ll f(int cur, int p, int n, vector<vector<ll>> &dp) {
        if(!cur)
            return 1;
        
        if(dp[cur][n] != -1) return dp[cur][n];
        ll ans = 0;
        for(int i = 1; i<=n; i++) {
            ll res = cur - pow(i, p);
            if(res >= 0)
                ans += f(res, p, i - 1,dp) % MOD;
        }
        return dp[cur][n] = ans % MOD;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1,-1));
        return f(n, x, n,dp);
    }
};