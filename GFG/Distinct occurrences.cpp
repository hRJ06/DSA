/*You are required to complete this method*/

class Solution
{
    private:
    int MOD = 1e9 + 7;
    int f(int i,int j,int n,int m,vector<vector<int>> &dp,string s,string t) {
        if(j >= m) return 1;
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != t[j]) {
            return dp[i][j] = f(i + 1,j,n,m,dp,s,t);
        }
        else {
            return dp[i][j] = (f(i + 1,j + 1,n,m,dp,s,t) + f(i + 1,j,n,m,dp,s,t)) % MOD;
        }
    }
    public:
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int n = s.length(), m = t.length();
      vector<vector<int>> dp(n, vector<int>(m, -1));
      return f(0,0,n,m,dp,s,t);
    }
};
 