class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int[] dif = new int[26];
        int n = s1.length();
        for(int i = 0; i<n; i++) {
            dif[s1.charAt(i) - 'a']++;
            dif[s2.charAt(i) - 'a']--;
        }
        for(int i = 0; i<26; i++) {
            if(dif[i] > 0) return false;
        }
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(s1.charAt(i) != s2.charAt(i)) count++;
        }
        return count <= 2;
    }
}