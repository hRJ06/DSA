typedef long long ll;
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int MOD = 1e9 + 7;
        ll ans = 0;
        vector<int> bit(31,0);
        for(auto &i : nums) {
            int x = i;
            int index = 0;
            while(x) {
                if(x & 1) bit[index]++;
                x >>= 1;
                index++;
            }
        }
        for(int i = 0; i<k; i++) {
            ll store = 0;
            for(int j = 0; j<31; j++) {
                if(bit[j]) {
                    store += 1LL * pow(2,j);
                    bit[j]--;
                }
            }
            ll total = (store % MOD * store % MOD) % MOD;
            ans = (ans % MOD + total % MOD) % MOD;
        }
        return ans;
    }
};
