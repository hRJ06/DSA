class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> mp;
        int i = 0, j = 0, n = nums.size();
        int ans = INT_MIN;
        while(j < n) {
            mp[nums[j]]++;
            while(mp.rbegin()->first - mp.begin()->first > limit) {
                mp[nums[i]]--;
                if(!mp[nums[i]])
                    mp.erase(nums[i]);
                i++;
            }
            j++;
            ans = max(ans,j - i);
        }
        return ans;
    }
};