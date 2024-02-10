class Solution {
private:
    int f(vector<vector<int>> &dp,string &s,int i,int j) {
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = s[i] != s[j] ? 0 : f(dp,s,i + 1,j - 1);
    }
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                ans += f(dp,s,i,j);
            }
        }
        return ans;
    }
};