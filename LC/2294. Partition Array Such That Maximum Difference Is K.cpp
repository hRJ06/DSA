class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans = 1, n = nums.size();
        sort(nums.begin(),nums.end());
        int a = nums[0], b = nums[0];
        for(int i = 1; i<n; i++) {
            a = min(a, nums[i]);
            b = max(b, nums[i]);
            if(b - a > k) {
                ans++;
                a = b = nums[i];
            }
        }
        return ans;
    }
};