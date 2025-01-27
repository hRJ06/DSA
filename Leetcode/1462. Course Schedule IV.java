class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        HashMap<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[numCourses];
        int n = prerequisites.length;
        for(int i = 0; i<n; i++) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj.computeIfAbsent(u, (k) -> new ArrayList<Integer>()).add(v);
            indegree[v]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i<numCourses; i++) {
            if(indegree[i] == 0) q.offer(i);
        }
        List<HashSet<Integer>> parent = new ArrayList<>();
        for(int i = 0; i<numCourses; i++) {
            parent.add(new HashSet<Integer>());
        }
        while(!q.isEmpty()) {
            int node = q.poll();
            for(Integer neighbour : adj.getOrDefault(node, new ArrayList<>())) {
                parent.get(neighbour).add(node);
                parent.get(neighbour).addAll(parent.get(node));
                if(--indegree[neighbour] == 0) q.offer(neighbour);
            }
        }
        List<Boolean> ans = new ArrayList<>();
        int m = queries.length;
        for(int i = 0; i<m; i++) {
            int u = queries[i][0], v = queries[i][1];
            ans.add(parent.get(v).contains(u));
        }
        return ans;
    }
}