class Solution {
private:
    int m, n;
    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int f(int i, int j, int canTurn, int d, int val, vector<vector<int>> &grid) {
        if(i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != val) return 0;
        int val_ = (val != 2) ? 2 : 0;
        int ans = 1 + f(i + dir[d][0], j + dir[d][1], canTurn, d, val_, grid);
        if(canTurn) {
            int d_ = (d + 1) % 4;
            ans = max(ans, 1 + f(i + dir[d_][0], j + dir[d_][1], false, d_, val_, grid));
        }
        return ans;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] != 1) continue;
                for(int d = 0; d<4; d++) {
                    ans = max(ans, 1 + f(i + dir[d][0], j + dir[d][1], true, d, 2, grid));
                }
            }
        }
        return ans;
    }
};