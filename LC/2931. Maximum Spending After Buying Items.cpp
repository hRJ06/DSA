typedef long long ll;
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<int> store;
        int m = values.size(), n = values[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) 
                store.push_back(values[i][j]);
        }
        sort(store.begin(),store.end());
        int days = m * n;
        ll ans = 0;
        for(int day = 1; day<=days; day++) 
            ans += (1LL * day * store[day - 1]);
        return ans;
    }
};