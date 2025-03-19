class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size(), ans = 0;
            for(int i = 0; i<n - 2; i++) {
                if(!nums[i]) {
                    for(int j = i; j<=i + 2; j++) nums[j] ^= 1;
                    ans++;
                }
            }
            if(!nums[n - 1] or !nums[n - 2]) return -1;
            return ans;
        }
    };