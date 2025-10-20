typedef long long ll;
class Solution {
private:
    int ans = 0;
    ll f(int node, int par, unordered_map<int, vector<int>> &adj,vector<int> &values, int K) {
        ll total = values[node];
        for(auto &i : adj[node]) {
            if(i != par) {
                ll sum = f(i, node, adj, values, K);
                if(sum % K) total += sum;
                else ans++;
            }
        }
        return total;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        /* 
            1. Removing a subtree divisible by K still ensures that the remanining component is divisible by K.
            2. We cannot remove a node just because if it's divisible by K if any of it's child is not divisible by K.
        */
        unordered_map<int, vector<int>> adj;
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        ll sum = f(0, -1, adj, values, k);
        if(!(sum % k)) ans++;
        return ans;
    }
};