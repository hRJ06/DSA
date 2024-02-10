class Solution {
private:
    long long f(int i, int j, int n, vector<vector<vector<int>>> &dp, vector<vector<int>> &arr, int k) {
        if(i >= n or j >= n or k < 0) return 0;
        if(i == n - 1 and j == n - 1) return k == arr[i][j];
        if(dp[i][j][k] != -1) return dp[i][j][k];
        long long a = f(i + 1, j, n, dp, arr, k - arr[i][j]);
        long long b = f(i, j + 1, n, dp, arr, k - arr[i][j]);
        return dp[i][j][k] = a + b;
    }
public:
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return f(0, 0, n, dp, arr, k);
    }
};