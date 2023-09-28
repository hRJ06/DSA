class Solution {
  private:
    int dir[5] = {-1,0,1,0,-1};
    void dfs(int i,int j,int m,int n,vector<vector<int>> &grid) {
        if(i < 0 or i == m or j < 0 or j == n or !grid[i][j]) return;
        grid[i][j] = 0;
        for(int k = 0; k<4; k++)
            dfs(i + dir[k],j + dir[k + 1],m,n,grid);
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i<m; i++) {
            dfs(i,0,m,n,grid);
            dfs(i,n - 1,m,n,grid);
        }
        for(int j = 0; j<n; j++) {
            dfs(0,j,m,n,grid);
            dfs(m - 1,j,m,n,grid);
        }
        int ans = 0;
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(grid[i][j])
                    ans++;
        return ans;
    }
};