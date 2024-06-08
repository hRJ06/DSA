class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), total = 0;
        map<int,int> mp;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
            total += nums[i];
            total %= k;
            if(mp.find(total) != mp.end()) {
                if(i - mp[total] > 1) return true;
            }
            else 
                mp[total] = i;
        }
        return false;
    }
};