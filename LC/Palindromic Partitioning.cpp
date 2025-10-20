class Solution{
private:
    bool isPal(int i,int j,string &s) {
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
    int f(string &str,int i,int n,vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j = i; j<n; j++) {
            if(isPal(i,j,str)) {
                int cost = 1 + f(str,j + 1,n,dp);
                ans = min(ans,cost);
            }
        }
        return dp[i] = ans;
    }
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n,-1);
        return f(str,0,n,dp) - 1;
    }
};