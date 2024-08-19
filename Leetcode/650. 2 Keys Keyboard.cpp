class Solution {
private:
    vector<vector<int>> dp;
    int f(int cur, int copy, int n) {
        if(cur == n) return 0;
        if(cur > n) return 1e8;
        if(dp[cur][copy] != -1) return dp[cur][copy];
        int a = 2 + f(cur + cur, cur, n);
        int b = 1 + f(cur + copy, copy, n);
        return dp[cur][copy] = min(a, b);
    }
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        dp.resize(1001, vector<int>(1001, -1));
        return 1 + f(1, 1, n);
    }
};