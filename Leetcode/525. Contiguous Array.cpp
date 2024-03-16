class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int total = 0, ans = 0;
        for(int i = 0; i<n; i++) {
            total += !nums[i] ? -1 : 1;
            if(!total) 
                ans = i + 1;
            else if(mp.find(total) != mp.end()) {
                ans = max(ans,i - mp[total]);
            }
            else
                mp[total] = i;
        }
        return ans;
    }
};