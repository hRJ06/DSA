class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int small = arrays[0][0], large = arrays[0].back();
        int ans = INT_MIN, n = arrays.size();
        for(int i = 1; i<n; i++) {
            ans = max(ans, abs(arrays[i][0] - large));
            ans = max(ans, abs(arrays[i].back() - small));
            small = min(small, arrays[i][0]);
            large = max(large, arrays[i].back());
        }
        return ans;
    }
};