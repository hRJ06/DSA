class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,false);
        function<bool(int)> f = [&](int node) -> bool {
            if(node == destination) return true;
            vis[node] = true;
            for(auto &i : adj[node]) {
                if(!vis[i]) {
                    bool ans = f(i);
                    if(ans) return true;
                }
            }
            return false;
        };
        return f(source);
    }
};