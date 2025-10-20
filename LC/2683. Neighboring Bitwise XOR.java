class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int ans = 0, n = derived.length;
        for(int i = 0; i<n; i++) {
            ans ^= derived[i];
        }
        if(ans != 0) return false;
        return true;
    }
}