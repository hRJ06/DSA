class Solution {
    public int minimumLength(String s) {
        int n = s.length();
        int[] f = new int[26];
        for(int i = 0; i<n; i++) {
            int idx = s.charAt(i) - 'a';
            f[idx]++;
        }
        int ans = 0;
        for(int i = 0; i<26; i++) {
            if(f[i] > 1) {
                if(f[i] % 2 != 0) ans += 1;
                else ans += 2;
            }
            else if(f[i] > 0) ans++;
        }
        return ans;
    }
}