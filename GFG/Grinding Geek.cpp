class Solution{
    private:
    int f(int day,int n,int total,vector<int> &cost,vector<vector<int>> &dp) {
        if(day >= n or !total) return 0;
        if(dp[day][total] != -1) return dp[day][total];
        int a = f(day + 1,n,total,cost,dp);
        int b = 0;
        if(total >= cost[day]) b = 1 + f(day + 1,n,total - cost[day] + floor(9.0 * cost[day] / 10),cost,dp);
        return dp[day][total] = max(a,b);
    }
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<vector<int>> dp(n,vector<int>(total + 1,-1));
        return f(0,n,total,cost,dp);
    }
};