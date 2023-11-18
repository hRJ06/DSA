class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long total = 0;
        int l = 0, n = nums.size(), ans = 1;
        for(int i = 0; i<n; i++) {
            total += nums[i];
            while(l + 1 <= i and total + k < (1LL * nums[i] * (i - l + 1))) 
                total -= nums[l++];
            ans = max(ans,i - l + 1);
        }
        return ans;
    }
};