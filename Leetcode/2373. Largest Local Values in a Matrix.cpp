class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for(int i = 1; i<=n - 2; i++) {
            for(int j = 1; j<=n - 2; j++) {
                int result = max({grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1]});
                result = max({result, grid[i][j - 1], grid[i][j], grid[i][j + 1]});
                result = max({result, grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]});
                ans[i - 1][j - 1] = result;
            }
        }
        return ans; 
    }
};