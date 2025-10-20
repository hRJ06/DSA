class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0, cur = 0, i = 0, j = 0, n = nums.size();
        while(j < n) {
            cur += nums[j];
            mp[nums[j]]++;
            while(mp.size() < (j - i + 1)) {
                cur -= nums[i];
                mp[nums[i]]--;
                if(!mp[nums[i]]) mp.erase(nums[i]);
                i++;
            }
            ans = max(ans, cur);
            j++;
        }
        return ans;
    }
};