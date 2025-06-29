typedef long long ll;
class Solution {
private:
    int MOD = 1e9 + 7;
    int f(int l, vector<int> &nums, int n, int target) {
        int s = l + 1, e = n - 1;
        int ans = -1;
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(nums[m] + nums[l] > target) e = m - 1;
            else {
                ans = m;
                s = m + 1;
            }
        }
        return ans;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        ll ans = 0;
        sort(nums.begin(), nums.end());
        vector<ll> power(n, 1); 
        for(int i = 1; i<n; i++) {
            power[i] = (2 * power[i - 1]) % MOD;
        }
        for(int i = 0; i<n; i++) {
            int index = f(i, nums, n, target);
            ll total = 0;
            if(index != -1) {
                int length = index - i;
                total = power[length];
            }
            else {
                if((nums[i] * 2) <= target) total = (total + 1) % MOD;
            }
            ans = (ans + total) % MOD;
        }
        return ans;
    }
};