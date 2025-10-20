class Solution {
private:
    vector<vector<int>> f(vector<vector<int>> &grid, int n, int m) {
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans[j][n - i - 1] = grid[i][j];
            }
        }
        return ans;
    }
    int area(vector<vector<int>> &grid, int sr, int er, int sc, int ec) {
        /*
            First Row where 1 occurs,
            First Column Where 1 occurs.
            Last Row where 1 occurs,
            Last Column where 1 occurs
        */
        int fr = INT_MAX, fc = INT_MAX, lr = INT_MIN, lc = INT_MIN;
        for(int i = sr; i<er; i++) {
            for(int j = sc; j<ec; j++) {
                if(grid[i][j]) {
                    fr = min(fr, i);
                    fc = min(fc, j);
                    lr = max(lr, i);
                    lc = max(lc, j);
                }
            }
        }
        return fr != INT_MAX ? (lr - fr + 1) * (lc - fc + 1) : 0;
    }
    int helper(vector<vector<int>> &grid) {
        /* RC CR RR */
        int n = grid.size(), m = grid[0].size(), ans = INT_MAX;
        /* RC CR */
        for(int row = 1; row<n; row++) {
            for(int col = 1; col<m; col++) {
                /* RC */
                int a = area(grid, 0, row, 0, m); /* U */
                int b = area(grid, row, n, 0, col); /* BL */
                int c = area(grid, row, n, col, m); /* BR */

                ans = min(ans, a + b + c);

                /* CR */
                int d = area(grid, 0, row , 0, col + 1); /* TL */
                int e = area(grid, 0, row, col, m); /* TR */
                int f = area(grid, row, n, 0, m); /* B */

                ans = min(ans, d + e + f);
            }
        }
        /* RR */
        for(int r1 = 1; r1<n; r1++) {
            for(int r2 = r1 + 1; r2<n; r2++) {
                int a = area(grid, 0, r1, 0, m); /* T */
                int b = area(grid, r1, r2, 0, m); /* M */
                int c = area(grid, r2, n, 0, m); /* B */
                ans = min(ans, a + b + c);
            }
        }
        return ans;
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> rotated = f(grid, n, m);
        return min(helper(grid), helper(rotated));
    }
};