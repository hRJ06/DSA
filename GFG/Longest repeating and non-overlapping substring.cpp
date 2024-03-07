class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int ans = 0, index = 0;
        for(int i = 1; i<=n; i++) {
            for(int j = i + 1; j<=n; j++) {
                if(s[i - 1] == s[j - 1] and dp[i - 1][j - 1] + 1 <= j - i) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if(dp[i][j] > ans) {
                        ans = dp[i][j];
                        index = i - 1;
                    }
                }
            }
        }
        string store = "";
        if(ans > 0) {
            for(int i = index - ans + 1; i<=index; i++) {
                store += s[i];
            }
        }
        else
            store += "-1";
        return store;
    }
};