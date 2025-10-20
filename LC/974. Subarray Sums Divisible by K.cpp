class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int n = nums.size(), ans = 0, total = 0;
        for(int i = 0; i<n; i++) {
            total += nums[i];
            total %= k;
            if(total < 0) total += k;
            if(mp.find(total) != mp.end()) {
                ans += mp[total];
            }
            mp[total]++;
        }
        return ans;
    }
};