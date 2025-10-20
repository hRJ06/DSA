class Solution {
private:
    int helper(int i,int n,string &s,vector<int> &dp) {
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int a = helper(i + 1,n,s,dp);
        int b = 0;
        if(i + 1 < n and (s[i] == '1' or (s[i] == '2' and s[i + 1] <= '6')))
            b = helper(i + 2,n,s,dp);
        return dp[i] = a + b;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return helper(0,n,s,dp);
    }
};