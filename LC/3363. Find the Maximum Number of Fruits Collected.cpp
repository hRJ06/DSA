class Solution {
private:
    vector<vector<int>> dp;
    int f1(int i, int j, int n, vector<vector<int>> &fruits) {
        if(i >= j || j >= n || (i >= n - 1 and j >= n - 1)) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = fruits[i][j] + f1(i + 1, j - 1, n, fruits);
        int b = fruits[i][j] + f1(i + 1, j, n, fruits);
        int c = fruits[i][j] + f1(i + 1, j + 1, n, fruits);
        return dp[i][j] = max({a, b, c});
    }
    int f2(int i, int j, int n, vector<vector<int>> &fruits) {
        if(i <= j || i >= n || (i >= n - 1 and j >= n - 1)) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = fruits[i][j] + f2(i - 1, j + 1, n, fruits);
        int b = fruits[i][j] + f2(i, j + 1, n, fruits);
        int c = fruits[i][j] + f2(i + 1, j + 1, n, fruits);
        return dp[i][j] = max({a, b, c});
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int c1 = 0;
        for(int i = 0; i<n; i++) {
            c1 += fruits[i][i];
            fruits[i][i] = 0;
        }
        dp.resize(n, vector<int>(n, -1));
        int c2 = f1(0, n - 1, n, fruits);
        int c3 = f2(n - 1, 0, n, fruits);
        return c1 + c2 + c3;
    }
};