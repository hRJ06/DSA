class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), ans = 0;
        unordered_map<int,int> mp;
        while(j < n) {
            mp[nums[j]]++;
            if(mp[nums[j]] > k) {
                while(i < j and mp[nums[j]] > k) {
                    mp[nums[i]]--;
                    if(!mp[nums[i]]) mp.erase(nums[i]);
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
