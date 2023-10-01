typedef long long ll;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                for(int k = j + 1; k<n; k++) {
                    ll total = 1LL * (nums[i] - nums[j]) * nums[k];
                    ans = max(ans,total);
                }
            }
        }
        return ans;
    }
};