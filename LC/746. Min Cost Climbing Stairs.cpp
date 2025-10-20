class Solution {
private:
    int f(vector<int> &dp,vector<int> &cost,int i) {
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] +  min(f(dp,cost,i - 1),f(dp,cost,i - 2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(f(dp,cost,n - 1),f(dp,cost,n - 2));
    }
};