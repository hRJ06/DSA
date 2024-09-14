class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int store = *max_element(nums.begin(), nums.end());
        int ans = INT_MIN, cur = 0, n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] != store) 
                cur = 0;
            else {
                cur++;
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};