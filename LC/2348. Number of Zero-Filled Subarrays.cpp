typedef long long ll;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        for(int i = 0; i<n;) {
            if(nums[i]) {
                i++;
                continue;
            }
            int j = i;
            while(j < n and !nums[j]) j++;
            ll length = j - i;
            ans += (length * ll(length + 1)) / 2;
            i = j + 1;
        }
        return ans;
    }
};