class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = *max_element(begin(nums), end(nums)) + k;
        vector<int> freq(n + 1, 0);
        for(auto &i : nums) freq[i] += 1;
        for(int i = 1; i<=n; i++) {
            freq[i] += freq[i - 1];
        }
        int ans = INT_MIN;
        for(int i = 0; i<=n - k; i++) {
            int l = i - k, r = i + k;
            int count = freq[r] - (l > 0 ? freq[l - 1] : 0);
            int count_ = freq[i] - (i ? freq[i - 1] : 0);
            int conversion = count_ + min(numOperations, count - count_);
            ans = max(ans, conversion);
        }
        return ans;
    }
};