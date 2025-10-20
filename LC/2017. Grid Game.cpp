typedef long long ll;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        /* The main crux of the problem is that a robot can only move down once */
        ll ans = LLONG_MAX, a = 0;
        ll total = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        for(int i = 0; i<n; i++) {
            total -= grid[0][i];
            ll b = max(total, a);
            ans = min(ans, b);
            a += grid[1][i];
        }
        return ans;
    }
};