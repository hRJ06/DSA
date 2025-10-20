class DSU {
    List<Integer> rank = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();
    public DSU(int n) {
        for(int i = 0; i<=n; i++) {
            rank.add(0);
            parent.add(i);
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
}
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int[] ans = new int[2];
        int n = edges.length;
        DSU ds = new DSU(n);
        for(int i = 0; i<n; i++) {
            int u = edges[i][0], v = edges[i][1];
            if(ds.findUPar(u) != ds.findUPar(v)) {
                ds.UnionByRank(u, v);
            }
            else {
                ans[0] = u;
                ans[1] = v;
            }
        }
        return ans;
    }
}