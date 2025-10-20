class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size(), ans = 0;
            vector<vector<int>> dp(n, vector<int>(n, 2));
            unordered_map<int, int> mp;
            for(int i = 0; i<n; i++) mp[arr[i]] = i;
            for(int j = 2; j<n; j++) {
                for(int i = 1; i<j; i++) {
                    int first = arr[j] - arr[i];
                    if(mp.count(first) and mp[first] < i) {
                        dp[i][j] = 1 + dp[mp[first]][i];
                        ans = max(ans, dp[i][j]);
                    }
                }
            } 
            return ans < 2 ? 0 : ans;
        }
    };