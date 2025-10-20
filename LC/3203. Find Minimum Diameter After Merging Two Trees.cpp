class Solution {
private:
    unordered_map<int, vector<int>> build(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return adj;
    }
    pair<int, int> BFS(unordered_map<int, vector<int>> &adj, int startNode) {
        queue<int> q;
        q.push(startNode);
        unordered_map<int, bool> visited;
        visited[startNode] = true;   
        int farthestNode = startNode, dist = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int current = q.front();
                q.pop();
                farthestNode = current;
                for(auto &ng : adj.at(current)) {
                    if(!visited[ng]) {
                        visited[ng] = true;
                        q.push(ng);
                    }
                }
            }
            if(!q.empty()) dist++;
        }
        return {farthestNode, dist};
    }
    int f(unordered_map<int, vector<int>> &adj) {
        if(adj.empty()) return 0;
        auto [oneEnd, _] = BFS(adj, 0);
        auto [otherEnd, diameter] = BFS(adj, oneEnd);
        return diameter;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = build(edges1);
        unordered_map<int, vector<int>> adj2 = build(edges2);
        int d1 = f(adj1);
        int d2 = f(adj2);
        int d3 = ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1;
        return max({d1, d2, d3});
    }
};
