class Solution {
    private boolean bipartite(int node, int[] colors, HashMap<Integer, ArrayList<Integer>> adj, int color) {
        colors[node] = color;
        for(Integer neighbour : adj.getOrDefault(node, new ArrayList<>())) {
            if(colors[neighbour] != -1) {
                if(colors[node] == colors[neighbour]) return false;
            }
            else {
                if(!bipartite(neighbour, colors, adj, color != 0 ? 0 : 1)) return false;
            }
        }
        return true;
    }
    private int bfs(int node, HashMap<Integer, ArrayList<Integer>> adj, int n) {
        int level = 1;
        boolean[] v = new boolean[n]; /* Since undirected graph */
        Queue<Integer> q = new LinkedList<>();
        q.offer(node);
        v[node] = true;
        while(!q.isEmpty()) {
            int size = q.size();
            while(size-- > 0) {
                int top = q.poll();
                for(Integer neighbour : adj.getOrDefault(top, new ArrayList<>())) {
                    if(!v[neighbour]) {
                        q.offer(neighbour);
                        v[neighbour] = true;
                    }
                }
            }
            level++;
        }
        return level - 1;
    }
    private int f(int node, HashMap<Integer, ArrayList<Integer>> adj, boolean[] v, int[] groups) {
        int ans = groups[node];
        v[node] = true;
        for(Integer neighbour : adj.getOrDefault(node, new ArrayList<>())) {
            if(!v[neighbour]) ans = Math.max(ans, f(neighbour, adj, v, groups));
        }
        return ans;
    }
    public int magnificentSets(int n, int[][] edges) {
        /* If we are able to divide each connected component then we can clearly merge them into two distinct parts - Bipartite Graph */
        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>();
        for(int i = 0; i<edges.length; i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }
        int[] colors = new int[n];
        Arrays.fill(colors, -1);
        for(int i = 0; i<n; i++) {
            if(colors[i] != -1) continue;
            if(!bipartite(i, colors, adj, 0)) return -1;
        }
        int[] groups = new int[n]; /* For each component find out if I take ith node as root what is the maximum number of groups */
        for(int i = 0; i<n; i++) {
            groups[i] = bfs(i, adj, n);
        }
        /* Now for each node in a component go through and find the max group that can be formed */
        int ans = 0;
        boolean[] v = new boolean[n];
        for(int i = 0; i<n; i++) {
            if(!v[i]) {
                ans += f(i, adj, v, groups);
            }
        }
        return ans;
    }
}