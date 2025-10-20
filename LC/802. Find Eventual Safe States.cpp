class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(int i = 0; i<n; i++) {
            for(auto &j : graph[i]) {
                adj[j].push_back(i);
                ind[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i<n; i++) 
            if(!ind[i])
                q.push(i);
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &i : adj[node]) {
                ind[i]--;
                if(!ind[i])
                    q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};