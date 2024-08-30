typedef long long ll;
int LARGE_VALUE = 2e9;
class Solution {
private:
    ll Dijkstra(vector<vector<int>> &edges, int s, int d, int n) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &i : edges) {
            if(i[2] != -1) {
                adj[i[0]].push_back({i[1], i[2]});
                adj[i[1]].push_back({i[0], i[2]});
            }
        }
        set<pair<int,int>> st;
        vector<int> distance(n, INT_MAX);
        distance[s] = 0;
        st.insert({0, s});
        while(!st.empty()) {
            auto top = *(st.begin());
            st.erase(st.begin());
            int dist = top.first;
            int node = top.second;
            for(auto &ng : adj[node]) {
                if(dist + ng.second < distance[ng.first]) {
                    auto check = st.find({distance[ng.first], ng.first});
                    if(check != st.end())
                        st.erase({distance[ng.first], ng.first});
                    distance[ng.first] = dist + ng.second;
                    st.insert({distance[ng.first], ng.first});
                }
            }
        }
        return distance[d];
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        /* First try using current graph */
        ll distance = Dijkstra(edges, source, destination, n);
        if(distance < target) return {};
        bool ifEqual = distance != target ? false : true;
        if(ifEqual) {
            for(auto &i : edges) {
                if(i[2] != -1) continue;
                i[2] = LARGE_VALUE;
            }
            return edges;
        }
        /* Here it means neither less nor equal, as a result ifEqual is false */
        for(auto &i : edges) {
            if(i[2] != -1) continue;
            i[2] = ifEqual ? LARGE_VALUE : 1;
            if(!ifEqual) {
                ll distance = Dijkstra(edges, source, destination, n);
                if(distance <= target) {
                    ifEqual = true;
                    i[2] += target - distance;
                }
            }
        }
        if(!ifEqual) return {};
        return edges;
    }
};