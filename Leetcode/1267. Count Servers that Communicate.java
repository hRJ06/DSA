class Solution {
    private int f(int i, int j, int[][] grid, boolean[][] v) {
        if(v[i][j]) return 0;
        v[i][j] = true;
        int count = 1;
        for(int col = 0; col<grid[0].length; col++) {
            if(grid[i][col] != 0) count += f(i, col, grid, v);
        }
        for(int row = 0; row<grid.length; row++) {
            if(grid[row][j] != 0) count += f(row, j, grid, v);
        }
        return count;
    }
    public int countServers(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] v = new boolean[m][n];
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] != 0) {
                    int count = f(i, j, grid, v);
                    if(count > 1) ans += count;
                }
            }
        }
        return ans;
    }
}