class Solution {
    public boolean check(int[] nums) {
        int count = 0, n = nums.length;
        for(int i = 1; i<n; i++) {
            if(nums[i] < nums[i - 1]) count++;
        }
        return (count == 0) || (count == 1 && nums[n - 1] <= nums[0]);
    }
}