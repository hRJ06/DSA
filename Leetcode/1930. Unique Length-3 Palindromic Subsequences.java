class Solution {
    private static boolean f(String s, String check) {
        int j = 0, n = s.length();
        for(int i = 0; i<n && j<3; i++) {
            if(s.charAt(i) != check.charAt(j)) continue;
            j++;
        }
        return j >= 3;
    }
    public int countPalindromicSubsequence(String s) {
        int ans = 0;
        for(char a = 'a'; a<='z'; a++) {
            for(char b = 'a'; b<='z'; b++) {
                String store = "" + a + b + a;
                if(f(s, store)) ans++;
            }
        }
        return ans;
    }
}