class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long reachable = 0, i = 0, size = nums.size();
        while(reachable < n) {
            if(i < size and nums[i] <= reachable + 1) 
                reachable += nums[i++];
            else {
                reachable += (reachable + 1);
                ans++;
            }
        }
        return ans;
    }
};