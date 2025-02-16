class Solution {
    private boolean f(String s, int index, int target) {
        if(target < 0) return false;
        if(index >= s.length() && target == 0) return true;
        int length = s.length();
        StringBuilder sb = new StringBuilder();
        for(int i = index; i<length; i++) {
            sb.append(s.charAt(i));
            if(f(s, i + 1, target - Integer.valueOf(sb.toString()))) return true;
        }
        return false;
    }
    public int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i<=n; i++) {
            int sq = i * i;
            if(f(String.valueOf(sq), 0, i)) ans += sq;
        }
        return ans;
    }
}