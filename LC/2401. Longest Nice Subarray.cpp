class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int ans = 1, start = 0, n = nums.size(), and_result = 0;
            for(int end = 0; end<n; end++) {
                while((and_result & nums[end])) {
                    and_result ^= nums[start++];
                }
                /* unset remove bit which were part of exactly one number, else we wouldn't proceeded from previous steps */
                and_result |= nums[end];
                ans = max(ans, end - start + 1);
            }
            return ans;
        }
    };