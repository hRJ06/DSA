class Solution {
private:
    int dp[501][501];
    int f(int i,int j,vector<int> &diff,int x) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = diff[i + 1] - diff[i] + f(i + 2,j,diff,x);
        int b = diff[j] - diff[j - 1] + f(i,j - 2,diff,x);
        int c = x + f(i + 1,j - 1,diff,x);
        return dp[i][j] = min({a,b,c});
    }
public:
    int minOperations(string s1, string s2, int x) {
        int n = s1.length();
        vector<int> diff;
        for(int i = 0; i<n; i++) 
            if(s1[i] != s2[i]) diff.push_back(i);
        memset(dp,-1,sizeof(dp));
        int m = diff.size();
        if(m % 2) return -1;
        int ans = f(0,m - 1,diff,x);
        return ans;
    }
};