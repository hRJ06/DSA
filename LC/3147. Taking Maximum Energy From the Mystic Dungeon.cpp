class Solution {
private:
    vector<int> dp;
    int f(int index, vector<int> &energy, int n, int k) {
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        return dp[index] = energy[index] + f(index + k, energy, n, k);
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), ans = INT_MIN;
        dp.resize(n, -1);
        for(int i = 0; i<n; i++) {
            ans = max(ans, f(i, energy, n, k));
        }
        return ans;
    }
};