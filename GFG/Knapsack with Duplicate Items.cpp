// User function Template for C++

class Solution{
private:
    int f(int i,int W,int *val,int *wt,vector<vector<int>> &dp) {
        if(i < 0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        int take = 0;
        if(W >= wt[i]) take = val[i] + f(i,W - wt[i],val,wt,dp);
        int notTake = f(i - 1,W,val,wt,dp);
        return dp[i][W] = max(take,notTake);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W + 1,-1));
        return f(N - 1,W,val,wt,dp);
    }
};