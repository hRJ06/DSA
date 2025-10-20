class Solution {
private:
    void dfs(vector<vector<int>> &v, int i, int j) {
        if(i < 0 or i >= v.size() or j < 0 or j >= v[0].size() or v[i][j]) return;
        v[i][j] = 1;
        dfs(v, i + 1, j);
        dfs(v, i - 1, j);
        dfs(v, i, j + 1);
        dfs(v, i, j - 1);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = 0;
        vector<vector<int>> v(r * 3, vector<int>(c * 3, 0));
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(grid[i][j] == '/') {
                    v[i * 3][j * 3 + 2] = 1;
                    v[i * 3 + 1][j * 3 + 1] = 1;
                    v[i * 3 + 2][j * 3] = 1;
                } 
                else if(grid[i][j] == '\\') {
                    v[i * 3][j * 3] = 1;
                    v[i * 3 + 1][j * 3 + 1] = 1;
                    v[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        int m = v.size(), n = v[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(!v[i][j]) {
                    ans++;
                    dfs(v, i, j);
                }
            }
        }
        return ans;
    }
};
