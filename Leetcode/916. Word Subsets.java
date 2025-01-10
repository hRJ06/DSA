class Solution {
    private boolean f(String s, int[] v) {
        int[] f = new int[26];
        int m = s.length();
        for(int i = 0; i<m; i++) {
            char ch = s.charAt(i);
            int idx = ch - 'a';
            f[idx]++;
        }
        for(int i = 0; i<26; i++) {
            if(f[i] < v[i]) return false;
        }
        return true;
    }
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> ans = new ArrayList<>();
        int[] v = new int[26];
        for(String s : words2) {
            int[] f = new int[26];
            int m = s.length();
            for(int i = 0; i<m; i++) {
                char ch = s.charAt(i);
                int idx = ch - 'a';
                f[idx]++;
                v[idx] = Math.max(v[idx], f[idx]);
            }
        }
        for(String s : words1) {
            if(f(s, v)) ans.add(s);
        } 
        return ans;
    }
}