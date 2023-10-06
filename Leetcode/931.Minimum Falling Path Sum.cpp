class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i<n; i++) 
            dp[m - 1][i] = matrix[m - 1][i];
        for(int i = m - 2; i>=0; i--) {
            for(int j = 0; j<n; j++) {
                int a = (j - 1 >= 0) ? dp[i + 1][j - 1] : INT_MAX;
                int b = dp[i + 1][j];
                int c = (j + 1 < n) ? dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({a, b, c});
            }
        }
        int minPathSum = INT_MAX;
        for (int i = 0; i < n; i++) 
            minPathSum = min(minPathSum, dp[0][i]);
        return minPathSum;
    }
};
