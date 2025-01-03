class Solution {
    public int waysToSplitArray(int[] nums) {
        int ans = 0, n = nums.length;
        long[] prefix = new long[n];
        long[] suffix = new long[n];
        for(int i = 0; i<n; i++) {
            prefix[i] = nums[i] + (i > 0 ? prefix[i - 1] : 0);
            suffix[n - i - 1] = nums[n - i - 1] + (i > 0 ? suffix[n - i] : 0);
        }
        for(int i = 0; i<n - 1; i++) {
            if(prefix[i] >= suffix[i + 1]) ans++;
        }
        return ans;
    }
}