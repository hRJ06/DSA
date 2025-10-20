typedef long long ll;
class Solution {
private:
    vector<ll> dp;
    ll f(int index, int n, vector<vector<int>> &q) {
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        ll a = f(index + 1, n, q);
        ll b = q[index][0] + f(index + q[index][1] + 1, n, q);
        return dp[index] = max(a, b);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n, -1);
        return f(0, n, questions);
    }
};