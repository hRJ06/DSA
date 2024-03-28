class Solution {
  private:
    void Dijkstra(int start,vector<int> &distance,unordered_map<int,vector<pair<int,int>>> &mp) {
        distance[start] = 0;
        set<pair<int,int>> s;
        s.insert({0,start});
        while(!s.empty()) {
            auto top = *(s.begin());
            int d = top.first;
            int node = top.second;
            s.erase(s.begin());
            for(auto &ng : mp[node]) {
                if(d + ng.second < distance[ng.first]) {
                    auto record = s.find({distance[ng.first],ng.first});
                    if(record != s.end()) {
                        s.erase(record);
                    }
                    distance[ng.first] = d + ng.second;
                    s.insert({distance[ng.first],ng.first});
                }
            }
        }
    }
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto &i : edges) {
            mp[i[0]].push_back({i[1],i[2]});
            mp[i[1]].push_back({i[0],i[2]});
        }
        int cities = INT_MAX;
        int ans = -1;
        for(int i = 0; i<n; i++) {
            vector<int> distance(n,INT_MAX);
            Dijkstra(i,distance,mp);
            int reachable = 0;
            for(auto &j : distance) {
                if(j <= distanceThreshold)
                    reachable++;
            }
            if(reachable <= cities) {
                cities = reachable;
                ans = i;
            }
        }
        return ans;
    }
};