typedef long long ll;
class Solution {
private:
    vector<vector<ll>> dp;
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        dp.resize(m, vector<ll>(n, 0));
        for(int i = 0; i<n; i++) 
            dp[m - 1][i] = points[m - 1][i];
        for(int i = m - 2; i>=0; i--) {
            vector<ll> left(n, 0), right(n, 0);
            left[0] = dp[i + 1][0];
            for(int j = 1; j<n; j++) {
                left[j] = max(left[j - 1] - 1, dp[i + 1][j]);
            }
            right[n - 1] = dp[i + 1][n - 1];
            for(int j = n - 2; j>=0; j--) {
                right[j] = max(right[j + 1] - 1, dp[i + 1][j]);
            }
            for(int j = 0; j<n; j++) {
                dp[i][j] = points[i][j] + max(left[j], right[j]);
            }
        }
        ll ans = LLONG_MIN;
        for(int i = 0; i < n; i++) 
            ans = max(ans, dp[0][i]);
        
        return ans;
    }
};
