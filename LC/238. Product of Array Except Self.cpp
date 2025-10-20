class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(nums), suf(nums), ans(n);
        partial_sum(begin(pre), end(pre), begin(pre), multiplies<int>());       
        partial_sum(rbegin(suf), rend(suf), rbegin(suf), multiplies<int>());    
        for(int i = 0; i<n; i++)
            ans[i] = (i ? pre[i-1] : 1) * (i+1 < n ? suf[i + 1] : 1);
        return ans;
    }
};