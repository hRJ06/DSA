class Solution {
private:
    int f(vector<int> &nums, int i, int j, int total,vector<vector<int>> &dp) {
        if(j - i < 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        int op1 = 0, op2 = 0, op3 = 0;
        if(total == -1 or nums[i] + nums[i + 1] == total) op1 = 1 + f(nums, i + 2, j, (total != -1) ? total : nums[i] + nums[i + 1],dp);
        if(total == -1 or nums[j] + nums[j - 1] == total) op2 = 1 + f(nums, i, j - 2, (total != -1) ? total : nums[j] + nums[j - 1],dp);
        if(total == -1 or nums[i] + nums[j] == total) op3 = 1 + f(nums, i + 1, j - 1, (total != -1) ? total : nums[i] + nums[j],dp);
        return dp[i][j] = max(op1, max(op2, op3));
    }
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(nums, 0, n - 1, -1,dp);
    }
};
