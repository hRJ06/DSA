class Solution {
private:
    int MOD = 1e9 + 7;
    int f(int dices, int face, int target, vector<vector<int>> &dp) {
        if(!dices) {
            if(!target) return 1;
            return 0;
        }
        if(dp[dices][target] != -1) return dp[dices][target];
        int ans = 0;
        for(int i = 1; i<=face; i++) {
            if(target - i >= 0) {
                ans = (ans + f(dices - 1, face, target - i, dp)) % MOD;
            }
        }
        return dp[dices][target] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return f(n, k, target, dp);
    }
};
