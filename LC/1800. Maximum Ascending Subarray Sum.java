class Solution {
    public int maxAscendingSum(int[] nums) {
        int ans = nums[0], cur = nums[0], n = nums.length;
        for(int i = 1; i<n; i++) {
            if(nums[i] > nums[i - 1]) cur += nums[i];
            else cur = nums[i];
            ans = Math.max(ans, cur);
        }
        return ans;
    }
}