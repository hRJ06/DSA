class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(!k) return 0;
        int n = nums.size(), ans = 0, prod = 1;
        int l = 0, r = 0;
        while(r < n) {
            prod *= nums[r++];
            while(l < r and prod >= k) 
                prod /= nums[l++];
            ans += (r - l);
        }
        return ans;
    }
};