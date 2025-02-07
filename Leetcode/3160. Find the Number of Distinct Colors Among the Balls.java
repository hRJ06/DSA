class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        HashMap<Integer, Integer> color = new HashMap<>();
        HashMap<Integer, Integer> ballColor = new HashMap<>();
        int n = queries.length;
        int[] ans = new int[n];
        for(int i = 0; i<n; i++) {
            int b = queries[i][0], c = queries[i][1];
            if(ballColor.containsKey(b)) {
                int prev = ballColor.get(b);
                color.put(prev, color.get(prev) - 1);
                if(color.get(prev) <= 0) color.remove(prev);
            }
            color.put(c, color.getOrDefault(c, 0) + 1);
            ballColor.put(b, c);
            ans[i] = color.size();
        }
        return ans;
    }
}