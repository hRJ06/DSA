class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int K) {
        vector<int> dp(K + 1,-1);
        dp[0] = 0;
        for(auto &i : nums) {
            for(int j = K; j>=i; j--) {
                if(dp[j - i] != -1)
                    dp[j] = max(dp[j],dp[j - i] + 1);
            }
        }
        return dp[K];
    }
};