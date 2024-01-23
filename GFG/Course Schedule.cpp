class Solution {
public:
    vector<int> findOrder(int n, int m, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(auto &i : prerequisites) {
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }   
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(!indegree[i]) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto &i : adj[top]) {
                indegree[i]--;
                if(!indegree[i]) {
                    q.push(i);
                }
            }
        }
        return ans.size() < n ? vector<int>() : ans;
    }
};