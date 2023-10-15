typedef long long ll;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), MOD = 12345;
        vector<vector<int>> ans(m,vector<int>(n,1));
        ll r = 1;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                (ans[i][j] *= r) %= MOD;
                (r *= grid[i][j]) %= MOD;
            }
        }
        r = 1;
        for(int i = m - 1; i>=0; i--) {
            for(int j = n - 1; j>=0; j--) {
                (ans[i][j] *= r) %= MOD;
                (r *= grid[i][j]) %= MOD;
            }
        }
        return ans;
    }
};