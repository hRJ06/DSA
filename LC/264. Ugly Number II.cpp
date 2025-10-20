class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int t = 0, th = 0, f = 0;
        for(int i = 1; i<n; i++) {
            int two = 2 * dp[t];
            int three = 3 * dp[th];
            int five = 5 * dp[f];
            dp[i] = min({two, three, five});
            t += (dp[i] != two) ? 0 : 1;
            th += (dp[i] != three) ? 0 : 1;
            f += (dp[i] != five) ? 0 : 1;
        }
        return dp[n - 1];
    }
};