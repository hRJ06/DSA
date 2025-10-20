class DSU {
    List<Integer> rank = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();
    List<Integer> size = new ArrayList<>();
    public DSU(int n) {
        for(int i = 0; i<=n; i++) {
            rank.add(0);
            parent.add(i);
            size.add(1);
        }
    }
    public int findUPar(int node) {
        if(node == parent.get(node)) return node;
        parent.set(node, findUPar(parent.get(node)));
        return parent.get(node);
    }
    public void UnionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_v == ulp_u) return;
        int rank_u = rank.get(u), rank_v = rank.get(v);
        if(rank_u < rank_v) {
            parent.set(ulp_u, ulp_v);
        }
        else if(rank_v < rank_u) {
            parent.set(ulp_v, ulp_u);
        }
        else {
            parent.set(ulp_v, ulp_u);
            rank.set(ulp_u, rank.get(ulp_u) + 1);
        }
    }
    public void UnionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size.get(ulp_u) < size.get(ulp_v)) {
            parent.set(ulp_u, ulp_v);
            size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u));
        }
        else {
            parent.set(ulp_v, ulp_u);
            size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));
        }
    }
}
class Solution {
    private boolean f(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        DSU ds = new DSU(n * n);
        int[] dir = {-1, 0, 1, 0, -1};
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] != 1) continue;
                for(int k = 0; k<4; k++) {
                    int ni = i + dir[k];
                    int nj = j + dir[k + 1];
                    if(f(ni, nj, n) && grid[ni][nj] == 1) {
                        int nodeNo = i * n + j;
                        int newNodeNo = ni * n + nj;
                        ds.UnionBySize(nodeNo, newNodeNo);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) continue;
                Set<Integer> adj = new HashSet<>();
                for(int k = 0; k<4; k++) {
                    int ni = i  + dir[k];
                    int nj = j + dir[k + 1];
                    if(f(ni, nj, n) && grid[ni][nj] == 1) {
                        adj.add(ds.findUPar(ni * n + nj));
                    }
                }
                int size = 0;
                for(Integer ng : adj) {
                    size += ds.size.get(ng);
                }
                ans = Math.max(ans, size + 1);
            }
        }
        if(ans == 0) ans = Math.max(ans, n * n);
        return ans;
    }
}