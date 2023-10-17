// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V,0);
        vector<vector<int>> adjR(V);
        for(int i = 0; i<V; i++) {
            for(auto &j : adj[i]) {
                adjR[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i<V; i++) if(!indegree[i]) q.push(i);
        set<int> s;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            s.insert(node);
            for(auto &i : adjR[node]) {
                indegree[i]--;
                if(!indegree[i]) q.push(i);
            }
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
    }
};