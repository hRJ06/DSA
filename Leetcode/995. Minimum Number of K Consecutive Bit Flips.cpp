class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, ans = 0;
        vector<int> isFlip(n, 0);
        for(int i = 0; i<n; i++) {
            if(i >= k) count -= isFlip[i - k];
            if(!nums[i] and !(count & 1) || nums[i] and (count & 1)) {
                if(i + k > n) return -1;
                count++;
                ans++;
                isFlip[i] = 1;
            }
        }   
        return ans;
    }
};