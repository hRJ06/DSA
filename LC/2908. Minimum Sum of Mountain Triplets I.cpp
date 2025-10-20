class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n,INT_MIN), s(n,INT_MIN);
        p[0] = nums[0];
        s[n - 1] = nums[n - 1];
        for(int i = 1; i<n; i++) p[i] = min(nums[i],p[i - 1]);
        for(int i = n - 2; i>=0; i--) s[i] = min(nums[i],s[i + 1]);
        int ans = INT_MAX;
        for(int i = 1; i<n - 1; i++) {
            int a = p[i - 1], b = s[i + 1];
            if(a < nums[i] and b < nums[i])
                ans = min(ans,a + b + nums[i]);
        }
        return ans != INT_MAX ? ans : -1;
    }
};