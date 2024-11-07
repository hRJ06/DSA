class Solution {
private:
    vector<vector<int>> dp;
    int M, N;
    int f(vector<vector<int>> &grid, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        int a = 0, b = 0, c = 0;
        if(i - 1 >= 0 and j + 1 < N and grid[i - 1][j + 1] > grid[i][j]) a = 1 + f(grid, i - 1, j + 1);
        if(j + 1 < N and grid[i][j + 1] > grid[i][j]) b = 1 + f(grid,i, j + 1);
        if(i + 1 < M and j + 1 < N and grid[i + 1][j + 1] > grid[i][j]) c = 1 + f(grid,i + 1, j + 1);
        return dp[i][j] = max({a, b, c});
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        M = m;
        N = n;
        int ans = 0;
        dp.resize(m, vector<int>(n, -1));
        for(int i = 0; i<m; i++) 
            ans = max(ans, f(grid, i, 0));
        return ans;
    }
};