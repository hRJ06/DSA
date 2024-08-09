class Solution {
private:
    bool f(vector<vector<int>>& grid, int r, int c) {
        unordered_set<int> s;
        for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                int x = grid[r + i][c + j];
                if(x < 1 or x > 9 or s.count(x)) 
                    return false;
                else 
                    s.insert(x);
            }
        }
        int total = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        for(int i = 0; i<3; i++) {
            if(grid[r + i][c] + grid[r + i][c+1] + grid[r + i][c+2] != total) return false;
            if(grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != total) return false;
        }
        if(grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != total) return false;
        if(grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != total) return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = 0;
        for(int i = 0; i<=r - 3; i++) {
            for(int j = 0; j<=c - 3; j++) {
                if(f(grid, i, j)) 
                    ans++;
            }
        }
        return ans;
    }
};
