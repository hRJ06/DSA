class Solution {
    private int BFS(int startNode, HashMap<Integer, ArrayList<Integer>> adj, boolean[] v) {
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.offer(new Pair(startNode, 0));
        int ans = 0;
        while(!q.isEmpty()) {
            Pair<Integer, Integer> p = q.poll();
            Integer node = p.getKey();
            Integer dist = p.getValue();
            for(int neighbour : adj.getOrDefault(node, new ArrayList<>())) {
                if(!v[neighbour]) {
                    v[neighbour] = true;
                    q.offer(new Pair(neighbour, dist + 1));
                    ans = Math.max(ans, dist + 1);
                }
            }
        }
        return ans;
    }
    public int maximumInvitations(int[] favorite) {
        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>();
        int n = favorite.length;
        for(int i = 0; i<n; i++) {
            int u = i;
            int v = favorite[i];
            adj.computeIfAbsent(v, k -> new ArrayList<Integer>()).add(u);
        }
        int fullCycles = 0;
        int semiCycles = 0;
        boolean[] visited = new boolean[n];
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                HashMap<Integer, Integer> count = new HashMap<>();
                int curNode = i;
                int nodeCount = 0;
                while(!visited[curNode]) {
                    visited[curNode] = true;
                    count.put(curNode, nodeCount);
                    int nextNode = favorite[curNode];
                    nodeCount++;
                    if(count.containsKey(nextNode)) {
                        int cycleLength = nodeCount - count.get(nextNode);
                        if(cycleLength != 2) fullCycles = Math.max(fullCycles, cycleLength);
                        else {
                            boolean[] v = new boolean[n];
                            v[curNode] = true;
                            v[nextNode] = true;
                            semiCycles += 2 + BFS(curNode, adj, v) + BFS(nextNode, adj, v);
                        }
                        break;
                    }
                    curNode = nextNode;
                }
            }
        }
        return Math.max(fullCycles, semiCycles);
    }
}