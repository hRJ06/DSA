class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        stable_partition(nums.begin(),nums.end(),[&](int n){return !(n & 1);});
        return nums;
    }
};