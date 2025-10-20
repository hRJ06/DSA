class Solution {
private:
    int m, n;
    void dfs(vector<vector<int>> &grid,vector<vector<bool>> &vis,int i,int j) {
        if(i < 0 or i >= m or j < 0 or j >= n or !grid[i][j] or vis[i][j]) return;
        vis[i][j] = true;
        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i, j + 1);
        dfs(grid, vis, i, j - 1);
    }
    int find(vector<vector<int>> &grid) {
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] and !vis[i][j]) {
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int island = find(grid);
        if(!island or island > 1) return 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]) {
                    grid[i][j] = 0;
                    island = find(grid);
                    if(!island or island > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};