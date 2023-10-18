class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto &i : relations) {
            adj[i[0] - 1].push_back(i[1] - 1);
            indegree[i[1] - 1]++;
        }
        queue<int> q;
        vector<int> times(n);
        for(int i = 0; i<n; i++) {
            if(!indegree[i]) q.push(i);
            times[i] = time[i];
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto &ng : adj[node]) {
                indegree[ng]--;
                times[ng] = max(times[ng],times[node] + time[ng]);
                if(!indegree[ng]) q.push(ng);
            }
        }
        return *max_element(times.begin(),times.end());
    }
};