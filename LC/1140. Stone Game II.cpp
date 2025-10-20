class Solution {
private:
    vector<vector<int>> dp;
    int f(vector<int> &piles, vector<int> &suffix, int index, int M) {
        if(index >= piles.size()) return 0;
        if(index + 2 * M >= piles.size()) return suffix[index];
        if(dp[index][M] != -1) return dp[index][M];
        int ans = 0;
        for(int x = 1; x<=2 * M; x++) 
            ans = max(ans, suffix[index] - f(piles, suffix, index + x, max(x, M)));
        return dp[index][M] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n, vector<int>(n, -1));
        vector<int> suffix(n, 0);
        suffix[n - 1] = piles[n - 1];
        for(int i = n - 2; i>=0; i--)
            suffix[i] = piles[i] + suffix[i + 1];
        return f(piles, suffix, 0, 1);
    }
};