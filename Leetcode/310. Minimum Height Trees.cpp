class Solution {
private:
    vector<int> dfs(int i,vector<bool> &vis,vector<vector<int>> &graph) {
        vector<int> lg, path;
        vis[i] = true;
        for(auto &adj : graph[i]) {
            if(!vis[adj]) 
                if(path = dfs(adj,vis,graph); path.size() > lg.size()) 
                    lg = move(path);
        }
        vis[i] = false;
        lg.push_back(i);
        return lg;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);
        for(auto &i : edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        auto path = dfs(dfs(0,vis,graph)[0],vis,graph);
        if(size(path) & 1) return {path[size(path) / 2]};
        return {path[size(path) / 2], path[size(path) / 2 - 1]};
    }
};