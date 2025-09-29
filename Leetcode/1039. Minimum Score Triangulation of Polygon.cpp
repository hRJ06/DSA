class Solution {
private:
    vector<vector<int>> dp;
    int f(int start, int end, vector<int> &values) {
        if(end - start + 1 < 3) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for(int k = start + 1; k<end; k++) {
            int left = f(start, k, values);
            int right = f(k, end, values);
            int polygon = values[start] * values[k] * values[end];
            ans = min(ans, left + polygon + right);
        }
        return dp[start][end] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.resize(n, vector<int>(n, -1));
        return f(0, n - 1, values);
    }
};