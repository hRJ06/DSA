class Solution {
private:
    int f(int i,char last,string &s,int k,int n,vector<vector<int>> &dp) {
        if(i >= n) return 0;
        if(dp[i][last - 'a'] != -1) return dp[i][last - 'a'];
        int t = 0, nT = 0;
        if(last == '{' or abs(s[i] - last) <= k)
            t = 1 + f(i + 1,s[i],s,k,n,dp);
        nT = f(i + 1,last,s,k,n,dp);
        return dp[i][last - 'a'] = max(t, nT);
    }
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(27, -1));
        return f(0,'{',s,k,n,dp);
    }
};