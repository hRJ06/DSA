class Solution {
private:
    int f(vector<vector<int>> &grid,int n,int prev,vector<vector<int>> &dp) {
        if(!n) {
            int ans = INT_MAX;
            for(int i = 0; i<grid.size(); i++) {
                if(i != prev) {
                    ans = min(ans,grid[n][i]);
                }
            }
            return ans;
        }
        if(dp[n][prev] != -1) return dp[n][prev];
        int ans = INT_MAX;
        for(int i = 0; i<grid.size(); i++) {
            if(i != prev) {
                int total = grid[n][i] + f(grid,n - 1,i,dp);
                ans = min(ans,total);
            }
        }
        return dp[n][prev] = ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n + 1,-1));
        return f(grid,n - 1,n,dp);
    }
};