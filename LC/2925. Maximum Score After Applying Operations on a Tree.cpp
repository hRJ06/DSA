typedef long long ll;
class Solution {
private:
    ll f(int node,int par,bool notTaken,vector<int> &values,vector<vector<ll>> &dp,unordered_map<int,vector<int>> &adj) {
        if(adj[node].size() == 1 and node != 0) {
            if(notTaken) return values[node];
            return 0;
        }
        if(dp[node][notTaken] != -1) return dp[node][notTaken];
        ll take = values[node];
        for(auto &i : adj[node]) 
            if(i != par) 
                take += f(i,node,notTaken,values,dp,adj);
        ll notTake = 0;
        for(auto &i : adj[node])
            if(i != par)
                notTake += f(i,node,true,values,dp,adj);
        return dp[node][notTaken] = max(take,notTake);
    }
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        unordered_map<int,vector<int>> adj;
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return f(0,-1,0,values,dp,adj);
    }
};