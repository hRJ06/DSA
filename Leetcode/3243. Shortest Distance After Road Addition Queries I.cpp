typedef pair<int,int> p;
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<p>> mp;
        for(int i = 0; i<n - 1; i++) 
            mp[i].push_back({i + 1, 1});
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i<m; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            mp[u].push_back({v, 1});
            vector<int> dist(n, INT_MAX);
            priority_queue<p, vector<p>, greater<p>> pq;
            dist[0] = 0;
            pq.push({0,0});
            while(!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                int distance = top.first;
                int node = top.second;
                if(distance > dist[node]) continue;
                for(auto &ng : mp[node]) {
                    if(distance + ng.second < dist[ng.first]) {
                        dist[ng.first] = distance + ng.second;
                        pq.push({dist[ng.first], ng.first});
                    }
                }
            }
            ans[i] = dist[n - 1];
        }
        return ans;
    }
};