class Solution {
private:
    void f(int node, unordered_map<int, vector<int>> &adj, vector<int> &path) {
        while(!adj[node].empty()) {
            int ng = adj[node].back();
            adj[node].pop_back();
            f(ng, adj, path);
        }
        path.push_back(node);
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, pair<int,int>> deg; /* {node, {in, out}} */
        unordered_map<int, vector<int>> adj;
        for(auto &i : pairs) {
            adj[i[0]].push_back(i[1]);
            deg[i[0]].second++;
            deg[i[1]].first++;
        }
        int start = -1;
        for(auto &i : deg) {
            if(i.second.second - i.second.first == 1) {
                start = i.first;
                break;
            }
        }
        if(start == -1) start = pairs[0][0];
        vector<int> eulerPath;
        f(start, adj, eulerPath);
        reverse(begin(eulerPath), end(eulerPath));
        vector<vector<int>> ans;
        int n = eulerPath.size();
        for(int i = 0; i<n - 1; i++) {
            ans.push_back({eulerPath[i], eulerPath[i + 1]});
        }
        return ans;
    }
};