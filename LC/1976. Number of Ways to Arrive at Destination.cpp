class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            int MOD = 1e9 + 7;
            unordered_map<int, vector<pair<int, int>>> adj;
            for(auto &i : roads) {
                int u = i[0], v = i[1], t = i[2];
                adj[u].push_back({v, t});
                adj[v].push_back({u, t});
            }
            vector<long long> dist(n, LLONG_MAX);
            vector<int> ways(n, 0);
            dist[0] = 0;
            ways[0] = 1;
            set<pair<long long, int>> s;
            s.insert({0, 0});
            while(!s.empty()) {
                auto top = *(s.begin());
                s.erase(top);
                int node = top.second;
                long long distance = top.first;
                for(auto &ng : adj[node]) {
                    long long new_dist = distance + ng.second;
                    if(new_dist < dist[ng.first]) {
                        auto check = s.find({dist[ng.first], ng.first});
                        if(check != s.end()) {
                            s.erase(check);
                        }
                        dist[ng.first] = new_dist;
                        ways[ng.first] = ways[node];
                        s.insert({dist[ng.first], ng.first});
                    } 
                    else if(new_dist == dist[ng.first]) 
                        ways[ng.first] = (ways[ng.first] + ways[node]) % MOD;
                }
            }
            return ways[n - 1];
        }
    };