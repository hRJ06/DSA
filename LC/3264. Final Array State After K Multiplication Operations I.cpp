class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        for(int i = 0; i<k; i++) {
            auto find = min_element(nums.begin(), nums.end());
            *find *= mul;
        }
        return nums;
    }
};