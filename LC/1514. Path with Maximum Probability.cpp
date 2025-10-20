class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        int m = edges.size();
        for(int i = 0; i<m; i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
        vector<double> dist(n, 0);
        dist[start_node] = 1;
        set<pair<double,int>, greater<pair<double,int>>> s;
        s.insert({1.0, start_node});
        while(!s.empty()) {
            auto top = *(s.begin());
            s.erase(top);
            int node = top.second;
            double distance = top.first;
            for(auto &ng : adj[node]){
                if(ng.second * distance > dist[ng.first]) {
                    auto check = s.find({dist[ng.first], ng.first});
                    if(check != s.end()) {
                        s.erase(check);
                    }
                    dist[ng.first] = ng.second * distance;
                    s.insert({dist[ng.first], ng.first});
                }
            }
        }
        return dist[end_node];
    }
};