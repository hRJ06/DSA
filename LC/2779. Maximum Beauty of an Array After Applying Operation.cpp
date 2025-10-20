class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        vector<int> v(l + k + 2, 0);
        for(auto &i : nums) {
            int s = i - k;
            int e = i + k;
            v[s < 0 ? 0 : s] += 1;
            v[e + 1] -= 1;
        }
        int ans = INT_MIN, n = v.size();
        for(int i = 1; i<n; i++) {
            v[i] += v[i - 1];
            ans = max(ans, v[i]);
        }   
        return ans;
    }
};