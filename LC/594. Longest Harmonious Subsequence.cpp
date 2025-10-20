class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        sort(begin(nums), end(nums));
        int i = 0, j = 1, n = nums.size();
        while(j < n) {
            while((j < n) and (nums[j] - nums[i]) == 1) {
                j++;
            }
            if((nums[j - 1] - nums[i]) == 1) ans = max(ans, j - i);
            while(j < n and (nums[j] - nums[i]) > 1) i++;
            j++;
        }
        return ans;
    }
};