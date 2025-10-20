class Solution {
private:
    bool dfsBob(int bobPos, int parent, int time, vector<int> &bobVis, unordered_map<int, vector<int>> &adj) {
        bobVis[bobPos] = time;
        if(!bobPos) return true;
        for(auto &ng : adj[bobPos]) {
            if(ng != parent) {
                if(dfsBob(ng, bobPos, time + 1, bobVis, adj)) {
                    return true;
                }
            }
        }
        bobVis[bobPos] = -1;
        return false;
    }
    void dfsAlice(int node, int time, int parent, unordered_map<int, vector<int>> &adj, vector<int> &bobVis, int score, vector<int> &amount) {
        if(adj[node].size() <= 1 and node != 0) {
            ans = max(ans, score);
            return;
        }
        for(auto &ng : adj[node]) {
            if(ng != parent) {
                int extra = (bobVis[ng] != -1) 
                                ? (bobVis[ng] < (time + 1) ? 0 
                                    : (bobVis[ng] > (time + 1) ? amount[ng] 
                                    : amount[ng] / 2)) 
                                : amount[ng];
                dfsAlice(ng, time + 1, node, adj, bobVis, score + extra, amount);
            }
        }
    }
public:
    int ans = INT_MIN;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int, vector<int>> adj;
        for(auto &i : edges) {
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        /*
            DFS(Bob, 0)
            DFS(0, [leaf Nodes])
        */
        int n = edges.size();
        vector<int> bobVisited(n + 1, -1);
        dfsBob(bob, -1, 0, bobVisited, adj);
        int extra = (bobVisited[0] != -1) 
                                ? (bobVisited[0] < 0 ? 0 
                                    : (bobVisited[0] > 0 ? amount[0] 
                                    : amount[0] / 2)) 
                                : amount[0];
        dfsAlice(0, 0, -1, adj, bobVisited, extra, amount);
        return ans;
    }
};