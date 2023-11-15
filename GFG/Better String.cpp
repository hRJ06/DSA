class Solution {
  private:
    int f(string &s) {
        unordered_map<char,int> mp;
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i<=n; i++) {
            dp[i] = 2 * dp[i - 1];
            if(mp.count(s[i  - 1])) 
                dp[i] -= dp[mp[s[i - 1]]];
            mp[s[i - 1]] = i - 1;
        }
        return dp[n];
    }
  public:
    string betterString(string str1, string str2) {
        // code here
        int a = f(str1), b = f(str2);
        return b > a ? str2 : str1;
        
    }
};