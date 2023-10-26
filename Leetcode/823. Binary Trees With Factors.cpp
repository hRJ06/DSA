class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(), MOD = 1e9 + 7;
        sort(arr.begin(),arr.end());
        vector<long long> dp(n,1);
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++) mp[arr[i]] = i;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(!(arr[i] % arr[j]) and mp.count(arr[i] / arr[j]))
                    (dp[i] += (dp[j] * dp[mp[arr[i] / arr[j]]])) %= MOD;
            }
        }
        return accumulate(dp.begin(),dp.end(),0LL) % MOD;
    }
};