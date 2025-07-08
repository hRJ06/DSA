class Solution {
private:
    int f(int i, vector<vector<int>> &events, vector<vector<int>> &dp, int k, int n) {
        if(i >= n or !k) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int b = f(i + 1, events, dp, k, n);
        int ind = i;
        for(ind = i + 1; ind<n; ind++)
            if(events[ind][0] > events[i][1])
                break;
        int a = events[i][2] + f(ind, events, dp, k - 1, n);
        return dp[i][k] = max(a, b);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(0, events, dp, k, n);
    }
};