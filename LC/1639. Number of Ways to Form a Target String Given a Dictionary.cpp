typedef long long ll;
class Solution {
private:
    int MOD = 1e9 + 7;
    ll f(int target_i, int index, vector<vector<ll>> &freq, int m, string &target, vector<vector<ll>> &dp) {
        if(target_i >= target.length()) return 1; 
        if(index >= m) return 0;
        if(dp[target_i][index] != -1) return dp[target_i][index];
        ll ways = f(target_i, index + 1, freq, m, target, dp);
        if(freq[index][target[target_i] - 'a'] > 0) {
            ways += freq[index][target[target_i] - 'a'] * f(target_i + 1, index + 1, freq, m, target, dp);
            ways %= MOD;
        }
        return dp[target_i][index] = ways;
    }
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = words[0].size();
        vector<vector<ll>> freq(m, vector<ll>(26, 0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                freq[j][words[i][j] - 'a']++;
            }
        }
        vector<vector<ll>> dp(target.length(), vector<ll>(m, -1));
        return f(0, 0, freq, m, target, dp);
    }
};
