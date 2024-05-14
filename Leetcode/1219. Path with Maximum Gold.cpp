class Solution {
private:
    int f(int i,int j,int m,int n,vector<vector<int>> &grid) {
        if(i < 0 or j < 0 or i == m or j == n or !grid[i][j]) return 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        int ans = val + max({f(i + 1,j,m,n,grid),f(i - 1,j,m,n,grid),f(i,j + 1,m,n,grid),f(i,j - 1,m,n,grid)});
        grid[i][j] = val;
        return ans;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]) 
                    ans = max(ans,f(i,j,m,n,grid));
            }
        }
        return ans;
    }
};