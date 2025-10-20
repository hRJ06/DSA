class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[k], cM = nums[k];
        int i = k, j = k;
        while(i > 0 or j < n - 1) {
            int left = i > 0 ? nums[i - 1] : 0;
            int right = j < n - 1 ? nums[j + 1] : 0;
            cM = left < right ? min(cM,nums[++j]) : min(cM,nums[--i]);
            ans = max(ans,cM * (j - i + 1));
        }
        return ans;
    }
};