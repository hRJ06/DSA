class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        for(int i = n - 1; i>=0; i--) {
            for(int tranNo = 3; tranNo>=0; tranNo--) {
                if(tranNo % 2 == 0) {
                    dp[i][tranNo] = max(-prices[i] + dp[i + 1][tranNo + 1], dp[i + 1][tranNo]);
                }
                else {
                    dp[i][tranNo] = max(prices[i] + dp[i + 1][tranNo + 1], dp[i + 1][tranNo]);
                }
            }
        }
        return dp[0][0];
    }
};