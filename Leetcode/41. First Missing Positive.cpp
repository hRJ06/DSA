class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool contains = false;
        int n = nums.size();
        for(auto &i : nums) 
            if(i == 1) contains = true;
        if(!contains) return 1;
        if(n == 1) return 2;
        for(auto &i : nums) 
            if(i <= 0 or i > n) i = 1;
        for(int i = 0; i<n; i++) {
            int x = abs(nums[i]);
            if(nums[x - 1] > 0) nums[x - 1] *= -1;
        }
        for(int i = 0; i<n; i++) {
            if(nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};