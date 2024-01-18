class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1,-1);
        function<int(int)> f = [&](int n) -> int {
            if(n <= 1) return 1;
            if(dp[n] != -1) return dp[n];
            return dp[n] = f(n - 1) + f(n - 2);
        };
        return f(n);
    }
};