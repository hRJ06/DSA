class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int n = nums.size(), total = 0, ans = 0;
        mp[0] = 1;
        for(auto &i : nums) {
            total += i;
            if(mp.count(total - goal))
                ans += mp[total - goal];
            mp[total]++;
        }
        return ans;
    }
};