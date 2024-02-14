class Solution {
private:
    int step = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = step;
        step++;
        for(auto &it : adj[node]) {
            if(it != parent) {
                if(!vis[it]) {
                    dfs(it, node, vis, adj, tin, low, bridges);
                    low[node] = min(low[node], low[it]);
                    if(low[it] > tin[node]) {
                        bridges.push_back({min(it,node), max(it,node)});
                    }
                }
                else {
                    low[node] = min(low[node], low[it]);
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int v, vector<int> adj[]) {
        vector<int> vis(v, 0);
        int tin[v], low[v];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        sort(bridges.begin(),bridges.end());
        return bridges;
   