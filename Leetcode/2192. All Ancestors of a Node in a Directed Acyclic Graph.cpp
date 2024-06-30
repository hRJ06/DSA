class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            ind[i[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) 
            if(!ind[i])
                q.push(i);
        vector<set<int>> res(n);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto &i : adj[node]) {
                ind[i]--;
                if(!ind[i])
                    q.push(i);
                res[i].insert(node);
                for(auto &j : res[node])
                    res[i].insert(j);
            }
        }
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) 
            ans[i] = vector<int>(res[i].begin(), res[i].end());
        return ans;
    }
};
