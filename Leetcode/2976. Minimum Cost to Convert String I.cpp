typedef long long ll;
class Solution {
private:
    vector<ll> dijkstra(char ch, unordered_map<char, vector<pair<char,ll>>> &adj) {
        vector<ll> dist(26, LLONG_MAX);
        dist[ch - 'a'] = 0;
        priority_queue<pair<ll, char>, vector<pair<ll, char>>, greater<>> pq;
        pq.push({0, ch});
        while(!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();
            if(distance > dist[node - 'a']) continue;
            for(auto &i : adj[node]) {
                char ng = i.first;
                ll cost = i.second;
                if(distance + cost < dist[ng - 'a']) {
                    dist[ng - 'a'] = distance + cost;
                    pq.push({dist[ng - 'a'], ng});
                }
            }
        }
        return dist;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char,ll>>> adj;
        int n = original.size(), m = source.length();
        for(int i = 0; i<n; i++) 
            adj[original[i]].push_back({changed[i], cost[i]});
        vector<vector<ll>> costs(26, vector<ll>(26, LLONG_MAX));
        for(int i = 0; i<n; i++) {
            vector<ll> v = dijkstra(original[i], adj);
            costs[original[i] - 'a'] = v;
        }
        ll ans = 0;
        for(int i = 0; i<m; i++) {
            if(source[i] != target[i]) {
                if(costs[source[i] - 'a'][target[i] - 'a'] != LLONG_MAX) 
                    ans += costs[source[i] - 'a'][target[i] - 'a'];
                else 
                    return -1;
            }
        }
        return ans;
    }
};
