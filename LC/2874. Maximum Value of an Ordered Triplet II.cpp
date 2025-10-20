typedef long long ll;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefix(n), suffix(n);
        for(int i = 0; i<n; i++) {
            prefix[i] = nums[i];
            if(i > 0) prefix[i] = max(prefix[i],prefix[i - 1]);
        }
        for(int i = n - 1; i>=0; i--) {
            suffix[i] = nums[i];
            if(i < n - 1) suffix[i] = max(suffix[i],suffix[i + 1]);
        }
        ll ans = 0;
        for(int i = 1; i<n - 1; i++) {
            ll pref = prefix[i - 1];
            ll suff = suffix[i + 1];
            ans = max(ans,1LL * (pref - nums[i]) * suff);
        }
        return ans;
    }
};