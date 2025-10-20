class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            int res = abs(nums[i]);
            if(nums[res] < 0) 
                return res;
            nums[res] = -nums[res];
        }
        return n;
    }
};