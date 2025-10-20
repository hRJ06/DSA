class Solution {
private:
    int f(int ind,vector<int> &arr,int n,int k,vector<int> &dp) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int maxVal = 0, ans = 0;
        for(int j = ind; j<min(ind + k,n); j++) {
            maxVal = max(maxVal,arr[j]);
            ans = max(ans,maxVal * (j - ind + 1) + f(j + 1,arr,n,k,dp));
        }
        return dp[ind] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,n,k,dp);
    }
};