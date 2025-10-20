class Solution {
private:
    int d(int c,int n,int length) {
        return min(abs(c - n),length  - abs(c - n));
    }
    int f(int ringIndex,int keyIndex,string &ring,string &key,vector<vector<int>> &dp) {
        if(keyIndex >= key.length()) return 0;
        if(dp[ringIndex][keyIndex] != -1) return dp[ringIndex][keyIndex];
        int ans = INT_MAX;
        for(int i = 0; i<ring.size(); i++) {
            if(ring[i] != key[keyIndex]) continue;
            int steps = d(ringIndex,i,ring.length()) + 1 + f(i,keyIndex + 1,ring,key,dp);
            ans = min(ans,steps);
        }
        return dp[ringIndex][keyIndex] = ans;
    }
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.length(), m = key.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0,0,ring,key,dp);
    }
};