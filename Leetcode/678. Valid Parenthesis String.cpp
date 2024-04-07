class Solution {
private:
    int f(int i,int oc,int n,string &s,vector<vector<int>> &dp) {
        if(i >= n) return !oc;
        if(dp[i][oc] != -1) return dp[i][oc];
        bool ans = false;
        if(s[i] == '*') {
            ans |= f(i + 1,oc + 1,n,s,dp);
            if(oc)
                ans |= f(i + 1,oc - 1,n,s,dp);
            ans |= f(i + 1,oc,n,s,dp);
        }
        else if(s[i] == '(')
            ans |= f(i + 1,oc + 1,n,s,dp);
        else if(oc)
            ans |= f(i + 1,oc - 1,n,s,dp);
        return dp[i][oc] = ans;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0,0,n,s,dp);
    }
};