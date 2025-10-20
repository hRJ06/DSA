class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total = 0, cur = 0, ans = n;
        for(auto &i : nums)
            total = (total + i) % p;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
            cur = (cur + nums[i]) % p;
            mp[cur] = i;
            int req = (cur - total) % p;
            if(req < 0) req += p;
            if(mp.count(req)) ans = min(ans, i - mp[req]);
        }   
        return ans < n ? ans : -1;
    }
};