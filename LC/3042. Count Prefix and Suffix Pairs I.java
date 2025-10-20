class Solution {
    private boolean f(String s, String t) {
        int l1 = s.length(), l2 = t.length();
        if(l1 > l2) return false;
        boolean prefix = true, suffix = true;
        for(int i = 0; i<l1; i++) {
            if(s.charAt(i) != t.charAt(i)) {
                prefix = false;
                break;
            }
        }
        for(int i = 0; i<l1; i++) {
            if(s.charAt(l1 - i - 1) != t.charAt(l2 - i - 1)) {
                suffix = false;
                break;
            }
        }
        return prefix && suffix;
    }
    public int countPrefixSuffixPairs(String[] words) {
        int ans = 0, n = words.length;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if((i < j) && f(words[i], words[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
}