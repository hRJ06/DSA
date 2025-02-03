class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int ans = 1, cur_i = 1, cur_d = 1, n = nums.length;
        for(int i = 1; i<n; i++) {
            if(nums[i] > nums[i - 1]) cur_i++;
            else cur_i = 1;
            ans = Math.max(ans, cur_i);
        }
        for(int i = 1; i<n; i++) {
            if(nums[i] < nums[i - 1]) cur_d++;
            else cur_d = 1;
            ans = Math.max(ans, cur_d);
        }
        return ans;
    }
}