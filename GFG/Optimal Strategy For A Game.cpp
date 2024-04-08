typedef long long ll;
class Solution{
    private:
    ll f(int s,int e,int arr[],vector<vector<int>> &dp) {
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int a = arr[s] + min(f(s + 2,e,arr,dp),f(s + 1,e - 1,arr,dp));
        int b = arr[e] + min(f(s + 1,e - 1,arr,dp),f(s,e - 2,arr,dp));
        return dp[s][e] = max(a,b);
    }
    public:
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0,n - 1,arr,dp);
    }
};