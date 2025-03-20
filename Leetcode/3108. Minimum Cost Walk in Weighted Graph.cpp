class DSU {
    int rank[];
    int parent[];
    public DSU(int n) {
        rank = new int[n];
        parent = new int[n];
        for(int i = 0; i<n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    public int find(int node) {
        if(node != parent[node]) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    public void unionByRank(int u, int v) {
        int p1 = find(u);
        int p2 = find(v);
        if(p1 != p2) {
            if(rank[p1] < rank[p2]) parent[p1] = p2;
            else if(rank[p1] > rank[p2]) parent[p2] = p1;
            else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }   
}
class Solution {
    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        DSU ds = new DSU(n);
        for(int i = 0; i<edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            ds.unionByRank(u, v);
        }
        int[] cost = new int[n];
        Arrays.fill(cost, Integer.MAX_VALUE);
        for(int i = 0; i<edges.length; i++) {
            int parent = ds.find(edges[i][0]);
            cost[parent] = cost[parent] & edges[i][2];
        }       
        int m = query.length;
        int[] ans = new int[m];
        for(int i = 0; i<m; i++) {
            int u = ds.find(query[i][0]);
            int v = ds.find(query[i][1]);
            if(u != v) ans[i] = -1;
            else ans[i] = cost[u];
        }
        return ans;
    }
}