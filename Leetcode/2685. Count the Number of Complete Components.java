class DSU {
    int[] rank;
    int[] parent;
    int[] edge;
    int[] count;
    DSU(int n) {
        rank = new int[n];
        parent = new int[n];
        edge = new int[n];
        count = new int[n];
        for(int i = 0; i<n; i++) {
            rank[i] = 0;
            edge[i] = 0;
            count[i] = 1;
            parent[i] = i;
        }
    }   
    int find(int node) {
        if(parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    void union(int u, int v) {
        int pU = find(u);
        int pV = find(v);
        if(pU != pV) {
            if(rank[pU] < rank[pV]) {
                parent[pU] = pV;
                edge[pV] += edge[pU] + 1;
                count[pV] += count[pU];
            }
            else if(rank[pU] > rank[pV]) {
                parent[pV] = pU;
                edge[pU] += edge[pV] + 1;
                count[pU] += count[pV];
            }
            else {
                parent[pU] = pV;
                rank[pV]++;
                edge[pV] += edge[pU] + 1;
                count[pV] += count[pU];
            }
        }
        else edge[pU]++;
    }
}
class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        DSU ds = new DSU(n);
        int m = edges.length;
        for(int i = 0; i<m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            ds.union(u, v);
        }
        int ans = 0;
        Set<Integer> s = new HashSet<>();
        for(int i = 0; i<n; i++) {
            int parent = ds.find(i);
            if(!s.contains(parent)) {
                s.add(parent);
                int edge = ds.edge[parent];
                int node = ds.count[parent];
                if(edge != (node * (node - 1)) / 2) continue;
                ans++;
            }
        }
        return ans;
    }
}