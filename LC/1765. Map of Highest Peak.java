class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length, n = isWater[0].length;
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        int[][] ans = new int[m][n];
        boolean[][] vis = new boolean[m][n];
        for(int i = 0; i<m; i++) {
            Arrays.fill(vis[i], false);
        }
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(isWater[i][j] != 0) {
                    q.offer(new Pair<>(i, j));
                    ans[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }
        int[] dir = {-1, 0, 1, 0, -1};
        while(!q.isEmpty()) {
            int size = q.size();
            while(size-- > 0) {
                Pair<Integer, Integer> p = q.poll();
                int i = p.getKey(), j = p.getValue();
                for(int k = 0; k<4; k++) {
                    int ni = i + dir[k];
                    int nj = j + dir[k + 1];
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj]) {
                        q.offer(new Pair<>(ni, nj));
                        vis[ni][nj] = true;
                        ans[ni][nj] = 1 + ans[i][j];
                    }
                }
            }
        }
        return ans;
    }
}