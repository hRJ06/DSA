typedef long long ll;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        unordered_map<int,ll> mp;
        mp[nums[0]] = 0;
        ll ans = LLONG_MIN;
        for(int i = 1; i<n; i++) {
            int fin1 = nums[i] + k;
            int fin2 = nums[i] - k;
            if(mp.count(fin1)) {
                ans = max(ans,prefix[i] - mp[fin1]);
            }
            if(mp.count(fin2)) {
                ans = max(ans,prefix[i] - mp[fin2]);
            }
            if(mp.count(nums[i])) {
                mp[nums[i]] = min(mp[nums[i]],prefix[i - 1]);
            }
            else {
                mp[nums[i]] = prefix[i - 1];
            }
        }
        return ans != LLONG_MIN ? ans : 0;
    }
};