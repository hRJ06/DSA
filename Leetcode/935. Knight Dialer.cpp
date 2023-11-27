class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<int>> mp = {{4,6},{8,6},{7,9},{8,4},{3,9,0},{},{1,7,0},{6,2},{1,3},{2,4}};
    int f(int no, int req, vector<vector<int>> &dp) {
        if(!req) return 1;
        if(dp[req][no] != -1) return dp[req][no];
        int ans = 0;
        for(auto &i : mp[no]) 
            (ans += f(i, req - 1, dp) % MOD) %= MOD;
        return dp[req][no] = ans;
    }
public:
    int knightDialer(int n) {
        if(n <= 1) return 10;
        vector<vector<int>> dp(n + 1, vector<int>(10, -1));
        int ans = 0;
        for(int i = 0; i<10; i++) {
            if(i != 5) 
                (ans += (f(i, n - 1, dp) % MOD)) %= MOD;
        }
        return ans;
    }
};
