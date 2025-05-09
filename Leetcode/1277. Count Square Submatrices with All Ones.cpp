class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,  0));
        for(int i = 0; i<n; i++) dp[0][i] = matrix[0][i];
        for(int i = 0; i<m; i++) dp[i][0] = matrix[i][0];
        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                if(!matrix[i][j]) dp[i][j] = 0;
                else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
        int ans = 0;
        for(auto &i : dp)
            for(auto &j : i)
                ans += j;
        return ans;
    }
};