class Solution {
    private int f(int i, int j, int m, int n, int[][] grid) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] <= 0) return 0;
        int cur = grid[i][j];
        grid[i][j] = 0;
        int a = f(i + 1, j, m, n, grid);
        int b = f(i - 1, j, m, n, grid);
        int c = f(i, j + 1, m, n, grid);
        int d = f(i, j - 1, m, n, grid);
        return cur + a + b + c + d;
    }
    public int findMaxFish(int[][] grid) {
        int m = grid.length, n = grid[0].length, ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] > 0) {
                    ans = Math.max(ans, f(i, j, m, n, grid));
                }
            }
        }
        return ans;
    }
}