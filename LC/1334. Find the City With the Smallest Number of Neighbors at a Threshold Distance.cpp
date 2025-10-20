class Solution {
private:
    vector<int> djks(int node, unordered_map<int, vector<pair<int,int>>> &adj, int k, int n) {
        vector<int> dist(n, INT_MAX);
        dist[node] = 0;
        set<pair<int,int>> s;
        s.insert({0, node});
        while(!s.empty()) {
            auto top = *(s.begin());
            s.erase(s.begin());
            int node = top.second, distance = top.first;
            for(auto &i : adj[node]) {
                if(distance + i.second < dist[i.first]) {
                    auto find = s.find({dist[i.first], i.first});
                    if(find != s.end()) 
                        s.erase(find);
                    dist[i.first] = distance + i.second;
                    s.insert({dist[i.first], i.first});
                }
            }
        }
        vector<int> ans;
        for(auto &i : dist) {
            if(i != INT_MAX and i <= k) ans.push_back(i);
        }
        return ans;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &i : edges) {
            int u = i[0], v = i[1], w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int low = INT_MAX, ans = -1;
        for(int i = 0; i<n; i++) {
            vector<int> v = djks(i, adj, k, n);
            if(v.size() <= low)  {
                ans = i;
                low = v.size();
            }
        }
        return ans;

    }
};
