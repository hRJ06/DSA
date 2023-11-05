class Solution {
private:
    void dfs(int node,unordered_map<int,vector<int>> &adj,int &count,vector<int> &vis) {
        count++;
        vis[node] = true;
        for(auto &i : adj[node])
            if(!vis[i]) dfs(i,adj,count,vis);
    }
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &i : edges)
            adj[i[0]].push_back(i[1]);
        int ans = -1;
        for(int i = 0; i<n; i++) {
            int count = 0;
            vector<int> vis(n,false);
            dfs(i,adj,count,vis);
            if(count == n) {
                if(ans != -1) return -1;
                else ans = i;
            }
        }
        return ans;
    }
};