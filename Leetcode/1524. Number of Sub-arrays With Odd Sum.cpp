class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int MOD = 1e9 + 7, n = arr.size();
            int odd = 0, even = 0, total = 0, ans = 0;
            for(int i = 0; i<n; i++) {
                total += arr[i];
                if(total & 1) {
                    odd++;
                    ans = (ans + even + 1) % MOD;
                }
                else {
                    even++;
                    ans = (ans + odd) % MOD;
                }
            }
            return ans;
        }
    };