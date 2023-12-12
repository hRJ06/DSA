// User function Template for C++

class Solution{
private:
    int f(int r,int c,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &dp) {
        if(r >= n or r < 0 or c >= m or c < 0) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        int x = grid[r][c] + f(r - 1,c + 1,n,m,grid,dp);
        int y = grid[r][c] + f(r,c + 1,n,m,grid,dp);
        int z = grid[r][c] + f(r + 1,c + 1,n,m,grid,dp);
        return dp[r][c] = max({x,y,z});
    }
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = INT_MIN;
        for(int i = 0; i<n; i++) ans = max(ans,f(i,0,n,m,M,dp));
        return ans;
    }
};