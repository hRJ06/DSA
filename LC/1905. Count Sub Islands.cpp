class Solution {
private:
    void dfs(int i, int j, int m, int n, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        if(i < 0 or i >= m or j < 0 or j >= n or !grid2[i][j]) return;
        grid2[i][j] = 0;
        dfs(i + 1, j, m, n, grid1, grid2);
        dfs(i - 1, j, m, n, grid1, grid2);
        dfs(i, j + 1, m, n, grid1, grid2);
        dfs(i, j - 1, m, n, grid1, grid2);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size();
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid2[i][j] and !grid1[i][j]) {
                    dfs(i, j, m, n, grid1, grid2);
                }
            }
        }
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid2[i][j]) {
                    dfs(i, j, m, n, grid1, grid2);
                    ans++;
                }
            }
        }
        return ans;
    }
};