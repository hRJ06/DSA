// Back-end complete function Template for C++

class Solution{
private:
    void dfs(int node,vector<int> &v,unordered_map<int,vector<int>> &mp) {
        v[node] = 1;
        for(auto &i : mp[node]) if(!v[i]) dfs(i,v,mp);
    }
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        unordered_map<int,vector<int>> adj;
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {
                if(graph[i][j] and i != j)
                    adj[i].push_back(j);
            }
        }
        vector<vector<int>> ans(N, vector<int>(N,0));
        for(int i = 0; i<N; i++) 
            dfs(i,ans[i],adj);
        return ans;
    }
};