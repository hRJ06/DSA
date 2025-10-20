class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int left = 0;
        for(int i = 1; i<n - 1; i++) {
            if((nums[left] > nums[i] and nums[i + 1] > nums[i]) or (nums[left] < nums[i] and nums[i + 1] < nums[i])) {
                ans++;
                left = i;
            }
        }
        return ans;
    }
};