class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<=n - k; i++) {
            bool flag = true;
            for(int j = i + 1; j<i + k; j++) {
                if(nums[j] != nums[j - 1] + 1) {
                    flag = false;
                    break;
                }
            }
            ans.push_back(flag ? *max_element(nums.begin() + i, nums.begin() + i + k) : -1);
        }
        return ans;
    }
};