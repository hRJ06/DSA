class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);
        dist1[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int elapsed = top.first;
            int node = top.second;
            if(node == n and dist2[node] != INT_MAX) return dist2[node];
            int rounds = elapsed / change;
            if(rounds % 2) 
                elapsed = (rounds + 1) * change;
            for(auto &neighbour : adj[node]) {
                int new_time = elapsed + time;
                if(new_time < dist1[neighbour]) {
                    dist1[neighbour] = new_time;
                    pq.push({new_time, neighbour});
                } 
                else if(new_time != dist1[neighbour] and new_time < dist2[neighbour]) {
                    dist2[neighbour] = new_time;
                    pq.push({new_time, neighbour});
                }
            }
        }
        return -1; 
    }
};
