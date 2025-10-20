class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0;
        for(auto &i : nums)
            if(i) count++;
        int n = nums.size();
        for(int i = 0; i<n; i++)
            nums.push_back(nums[i]);
        n = nums.size();
        /* process for first window of count size */
        int ans = INT_MAX, zero = 0;
        for(int i = 0; i<count; i++) {
            if(!nums[i]) zero++;
        }
        ans = min(ans, zero);
        /* process for rest windows of count size */
        for(int i = 0, j = count; j<n; j++, i++) {
            if(!nums[i]) zero--;
            if(!nums[j]) zero++;
            ans = min(ans, zero);
        }
        return ans;
    }
};