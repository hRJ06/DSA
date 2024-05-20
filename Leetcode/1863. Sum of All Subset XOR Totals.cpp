class Solution {
private:
    int f(vector<int> &nums,int i,int cur) {
        if(i >= nums.size()) return cur;
        return f(nums,i + 1,cur) + f(nums,i + 1,cur ^ nums[i]);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return f(nums,0,0);
    }
};