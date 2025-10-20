class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int,vector<int>> adj;
        for(auto &i : adjacentPairs) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(auto &i : adj) {
            if(i.second.size() == 1) {
                ans.push_back(i.first);
                ans.push_back(i.second[0]);
                break;
            }
        }
        int g = adj.size();
        while(ans.size() < g) {
            int last = ans[ans.size() - 1], secondlast = ans[ans.size() - 2];
            if(adj[last][0] != secondlast) 
                ans.push_back(adj[last][0]);
            else 
                ans.push_back(adj[last][1]);
        }
        return ans;
    }
};