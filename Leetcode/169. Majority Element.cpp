class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el = -1, n = nums.size();
        for(int i = 0; i<n; i++) {
            if(!count) {
                count = 1;
                el = nums[i];
            }
            else if(nums[i] == el)
                count++;
            else
                count--;  
        }
        int check = 0;
        for(auto &i : nums) 
            if(i == el)
                check++;
        return check > (n / 2) ? el : -1;
    }
};