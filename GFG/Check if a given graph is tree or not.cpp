class Solution {
private:
    bool isCyclic(int start, int parent, unordered_map<int, vector<int>> &adj, vector<bool> &vis) {
        vis[start] = true;
        for(auto &i : adj[start]) {
            if(!vis[i]) {
                if (isCyclic(i, start, adj, vis))
                    return true;
            }
            else if(i != parent) {
                return true;
            }
        }
        return false;
    }
public:
    int isTree(int n, int m, vector<vector<int>>& v) {
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i<m; i++) {
            adj[v[i][0]].push_back(v[i][1]);
            adj[v[i][1]].push_back(v[i][0]);
        }
        if(isCyclic(0, -1, adj, vis))return 0;
        for(int i = 0; i<n; i++) {
            if(!vis[i])
                return 0;
        }
        return 1;
    }
};