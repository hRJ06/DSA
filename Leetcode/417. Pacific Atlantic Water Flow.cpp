class Solution {
private:
    int dir[5] = {-1,0,1,0,-1};
    void dfs(int i,int j,int m,int n,vector<vector<int>> &heights,vector<vector<bool>> &vis) {
        if(vis[i][j]) return;
        vis[i][j] = true;
        for(int k = 0; k<4; k++) {
            int nr = i + dir[k], nc = j + dir[k + 1];
            if(nr >= 0 and nr < m and nc >= 0 and nc < n and heights[nr][nc] >= heights[i][j])
                dfs(nr,nc,m,n,heights,vis);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> atl(m, vector<bool>(n,false));
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        for(int j = 0; j<n; j++) {
            dfs(0,j,m,n,heights,pac);
            dfs(m - 1,j,m,n,heights,atl);
        }
        for(int i = 0; i<m; i++) {
            dfs(i,0,m,n,heights,pac);
            dfs(i,n - 1,m,n,heights,atl);
        }
        vector<vector<int>> ans;
        for(int i = 0; i<m; i++) 
            for(int j = 0; j<n; j++)
                if(atl[i][j] and pac[i][j])
                    ans.push_back({i,j});
        return ans;
    }
};
