class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        int[] f = new int[n + 1];
        int count = 0;
        for(int i = 0; i<n; i++) {
            f[A[i]]++;
            if(f[A[i]] >= 2) count++;
            f[B[i]]++;
            if(f[B[i]] >= 2) count++;
            ans[i] = count;
        }
        return ans;
    }
}