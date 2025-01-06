class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] ans = new int[n];
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        int count = 0, sum = 0;
        for(int i = n - 1; i>=0; i--) {
            sum += count;
            if(boxes.charAt(i) != '0') count++;
            suffix[i] = sum;
        }
        count = 0;
        sum = 0;
        for(int i = 0; i<n; i++) {
            sum += count;
            if(boxes.charAt(i) != '0') count++;
            prefix[i] = sum;
        }
        for(int i = 0; i<n; i++) {
            ans[i] += (prefix[i] + suffix[i]);
        }
        return ans;
    }
}