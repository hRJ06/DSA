class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1, n = nums.size();
        vector<int> ans(n);
        for(auto &i : nums) {
            if(i < 0) {
                ans[neg] = i;
                neg += 2;
            }
            else {
                ans[pos] = i;
                pos += 2;
            }
        }
        return ans;
    }
};