class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1,-1);
        function<int(int)> f = [&](int n) -> int {
            if(!n) return 0;
            if(dp[n] != -1) return dp[n];
            int ans = 1e8;
            for(int i = 1; i * i <= n; i++)
                ans = min(ans,1 + f(n - i * i));
            return dp[n] = ans;
        };
        return f(n);
    }
};