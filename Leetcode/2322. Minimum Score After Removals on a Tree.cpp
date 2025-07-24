class Solution {
private:
    int f(int node, unordered_map<int, vector<int>> &adj, unordered_map<int, unordered_set<int>> &desc, vector<int> &score, vector<int> &nums, vector<bool> &v) {
        v[node] = true;
        desc[node].insert(node);
        int ans = nums[node];
        for(auto &i : adj[node]) {
            if(!v[i]) {
                ans ^= f(i, adj, desc, score, nums, v);
                desc[node].insert(i);
                desc[node].insert(desc[i].begin(), desc[i].end());
            }
        }
        return score[node] = ans;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, unordered_set<int>> desc;
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int n = nums.size();
        vector<int> score(n, 0);
        vector<bool> v(n, false);
        f(0, adj, desc, score, nums, v);
        int m = edges.size(), ans =  INT_MAX;
        for(int i = 1; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                if(desc[i].count(j)) {
                    int a = score[j];
                    int b = score[i] ^ score[j];
                    int c = score[0] ^ score[i];
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
                else if(desc[j].count(i)) {
                    int a = score[i];
                    int b = score[j] ^ score[i];
                    int c = score[0] ^ score[j];
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
                else {
                    int a = score[i];
                    int b = score[j];
                    int c = score[0] ^ score[i] ^ score[j];
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        return ans;
    }
};