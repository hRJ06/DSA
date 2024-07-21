class Solution {
private:
    vector<int> f(int k, vector<vector<int>> &g) {
        vector<int> in(k + 1, 0); /* 1 based indexing */
        unordered_map<int, vector<int>> adj;
        for(auto &i : g) {
            int u = i[0], v = i[1];
            in[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        for(int i = 1; i<=k; i++)
            if(!in[i]) q.push(i);
        vector<int> ans;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto &i : adj[top]) {
                in[i]--;
                if(!in[i]) 
                    q.push(i);
            }
        }
        return ans.size() != k ? vector<int>() : ans;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = f(k, rowConditions);
        vector<int> topoCol = f(k, colConditions);
        if(!topoRow.size() or !topoCol.size()) return {};
        vector<vector<int>> ans(k, vector<int>(k, 0));
        unordered_map<int,int> r, c;
        for(int i = 0; i<k; i++) {
            r[topoRow[i]] = i;
            c[topoCol[i]] = i;
        }
        for(int i = 1; i<=k; i++) {
            int row = r[i], col = c[i];
            ans[row][col] = i;
        }
        return ans;
    }
};