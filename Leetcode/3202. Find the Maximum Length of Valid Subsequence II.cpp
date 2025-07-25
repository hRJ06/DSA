class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 0));
        int ans = 0;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                int mod = (nums[i] + nums[j]) % k;
                dp[i][mod] = max(dp[i][mod], 1 + dp[j][mod]);
                ans = max(ans, dp[i][mod]);
            }
        }
        return ans + 1;
    }
};