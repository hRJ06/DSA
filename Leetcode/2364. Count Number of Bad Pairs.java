class Solution {
    public long countBadPairs(int[] nums) {
        long ans = 0;
        int n = nums.length;
        for(int i = 0; i<n; i++) {
            nums[i] -= i;
        }
        /*
            4 0 1 0
            (4, 0) (4, 1), (4, 0)
            (0, 1)
            (1, 0)
        */
        HashMap<Integer, Integer> count = new HashMap<>();
        for(int i = n - 1; i>=0; i--) {
            ans += (long)count.getOrDefault(nums[i], 0);
            count.put(nums[i], count.getOrDefault(nums[i], 0) + 1);
        }
        long total = ((long)n * (long)(n - 1)) / 2;
        return total - ans;
    }
}