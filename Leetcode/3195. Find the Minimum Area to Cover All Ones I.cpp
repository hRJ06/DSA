class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        /*
            First Row where 1 occurs,
            First Column Where 1 occurs.
            Last Row where 1 occurs,
            Last Column where 1 occurs
        */
        int m = grid.size(), n = grid[0].size();
        int fr = INT_MAX, fc = INT_MAX, lr = INT_MIN, lc = INT_MIN;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]) {
                    fr = min(fr, i);
                    fc = min(fc, j);
                    lr = max(lr, i);
                    lc = max(lc, j);
                }
            }
        }
        return (lr - fr + 1) * (lc - fc + 1);
    }
};