class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for(int b = 0; b<31; b++) {
            int t = 0;
            for(auto &i : nums) t += ((i >> b) & 1);
            if(t >= k) ans |= (1 << b);
        }
        return ans;
    }
};
