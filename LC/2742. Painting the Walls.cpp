class Solution {
private:
    int f(int i,int days,vector<int> &cost,vector<int> &time,vector<vector<int>> &dp) {
        if(days <= 0) return 0;
        if(i < 0) return 1e9;
        if(dp[i][days] != -1) return dp[i][days];
        int a = f(i - 1,days,cost,time,dp);
        int b = cost[i] + f(i - 1,days - time[i] - 1,cost,time,dp);
        return dp[i][days] = min(a,b);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n,vector<int>(n + 1,-1));
        return f(n - 1,n,cost,time,dp);
    }
};