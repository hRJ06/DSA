class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int ans = Integer.MIN_VALUE;
        int left = values[0], n = values.length;
        for(int i = 1; i<n; i++) {
            ans = Math.max(ans, left + values[i] - i);
            left = Math.max(left, values[i] + i);
        }
        return ans;
    }
}