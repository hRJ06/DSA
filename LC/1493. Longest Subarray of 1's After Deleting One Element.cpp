class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = INT_MIN, k = 1, n = nums.size();
        int s = 0, e = 0;
        while(e < n) {
            if(!nums[e]) k -= 1;
            while(k < 0) {
                if(!nums[s]) k += 1;
                s++;
            }
            ans = max(ans, e - s);
            e += 1;
        }
        return ans != n ? ans : n - 1;
    }
};