class Solution {
private:
    int f(vector<vector<int>> &grid,int i,int j,int k,vector<vector<vector<int>>> &dp,int m,int n) {
        if(i >= m) return 0;
        if(j >= n or k >= n or j < 0 or k < 0) return INT_MIN;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int ans = 0;
        for(int r1 = -1; r1<=1; r1++) {
            for(int r2 = -1; r2<=1; r2++) {
                ans = max(ans, f(grid,i + 1,j + r1,k + r2,dp,m,n));
            }
        }
        ans += (j != k) ? grid[i][j] + grid[i][k] : grid[i][j];
        return dp[i][j][k] = ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return f(grid,0,0,n - 1,dp,m,n);
    }
};