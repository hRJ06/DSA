class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        unordered_map<int,int> dp;
        sort(nums.begin(),nums.end());
        int ans = 1;
        for(auto &i : nums) {
            dp[i + 1] = dp[i] + 1;
            dp[i] = dp[i - 1] + 1;
            ans = max({ans, dp[i + 1], dp[i]});
        }
        return ans;
    }
};