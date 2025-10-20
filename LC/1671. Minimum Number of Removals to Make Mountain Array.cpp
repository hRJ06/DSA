class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        for(int i = 1; i<n; i++) {
            for(int j = i - 1; j>=0; j--) {
                if(nums[j] < nums[i])
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }

        for(int i = n - 2; i>=0; i--) {
            for(int j = i + 1; j<n; j++) {
                if(nums[j] < nums[i])
                    LDS[i] = max(LDS[i], 1 + LDS[j]);
            }
        }

        int ans = n;
        for(int i = 1; i<n; i++) {
            if(LIS[i] > 1 and LDS[i] > 1)
                ans = min(ans, n - LIS[i] - LDS[i] + 1);
        }
        return ans;
    }
};