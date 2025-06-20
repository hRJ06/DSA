class Solution {
    public int maxDistance(String s, int k) {
        /* Make sure to apply all the K operations at a stretch */
        char[][] d = {{'N', 'E'}, {'N', 'W'}, {'S', 'E'}, {'S', 'W'}};
        int ans = 0;
        for(int i = 0; i<4; i++) {
            int count = k, res = 0;
            for(int index = 0; index<s.length(); index++) {
                char c = s.charAt(index);
                if(c == d[i][0] || c == d[i][1]) res++; 
                else {
                    if(count > 0) {
                        res++;
                        count--;
                    }
                    else res--;
                }
                ans = Math.max(ans, res);
            }
        }
        return ans;
    }
}