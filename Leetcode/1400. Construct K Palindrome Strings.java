class Solution {
    public boolean canConstruct(String s, int k) {
        int n = s.length();
        if(n < k) return false;
        int[] f = new int[26];
        for(int i = 0; i<n; i++) {
            int idx = s.charAt(i) - 'a';
            f[idx]++;
        }
        int count = 0;
        for(int i = 0; i<26; i++) {
            if(f[i] % 2 != 0) count++;
        }
        return count > k ? false : true;
    }
}