class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        function<int(int,int)> f = [&](int i,int j) -> int {
            if(i == j) return 1;
            if(dp[i][j] != -1) return dp[i][j];
            int ans = INT_MAX;
            for(int k = i; k<j; k++)
                ans = min(ans,f(i,k) + f(k + 1,j));
            return dp[i][j] = (s[i] == s[j]) ? ans - 1 : ans;
        }; 
        return f(0,n - 1);
    }
};
