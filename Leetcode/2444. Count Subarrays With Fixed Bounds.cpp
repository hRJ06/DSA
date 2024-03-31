typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans = 0;
        int maxi = -1, mini = -1;
        int n = nums.size();
        for(int r = 0, l = 0; r<n; r++) {
            int ele = nums[r];
            if(ele < minK or ele > maxK) {
                l = r + 1;
                continue;
            }
            if(ele == maxK) maxi = r;
            if(ele == minK) mini = r;
            ans += max(min(maxi,mini) - l + 1, 0);
        }
        return ans;
    }
};