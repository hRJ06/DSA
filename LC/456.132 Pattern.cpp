class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int third = INT_MIN, n = nums.size();
        for(int i = n - 1; i>=0; i--) {
            if(nums[i] < third) return true;
            while(!s.empty() and nums[i] > s.top()) {
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};