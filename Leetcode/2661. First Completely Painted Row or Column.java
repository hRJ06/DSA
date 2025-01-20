class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        Map<Integer, Integer> row = new HashMap<>(), col = new HashMap<>();
        Map<Integer, Pair<Integer, Integer>> mp = new HashMap<>();
        int m = mat.length, n = mat[0].length;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp.put(mat[i][j], new Pair(i, j));
            }
        }
        int size = m * n;
        for(int i = 0; i<size; i++) {
            Pair<Integer, Integer> p = mp.get(arr[i]);
            int r = p.getKey();
            int c = p.getValue();
            row.put(r, row.getOrDefault(r, 0) + 1);
            col.put(c, col.getOrDefault(c, 0) + 1);
            if(row.get(r) >= n || col.get(c) >= m) return i;
        }
        return -1;
    }
}