class Solution {
    private static int f(int index, int cur, int target, int[] nums, int[][] dp) {
        if(index < 0) {
            if(cur != target) return 0;
            return 1;
        }
        if(dp[index][cur + 1000] != -1) return dp[index][cur + 1000];
        int a = f(index - 1, cur - nums[index], target, nums, dp);
        int b = f(index - 1, cur + nums[index], target, nums, dp);
        return dp[index][cur + 1000] = a + b;
    }
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int[][] dp = new int[n][2001];
        for(int i = 0; i<n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return f(n - 1, 0, target, nums,dp);
    }
}