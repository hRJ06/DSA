class Solution {
private:
    bool f(int target, vector<int> &nums, int k) {
        for(auto &i : nums) {
            if(i <= target) continue;
            target * 2 < i ? k -= (i - 1) / target : k--;
            if(k < 0) return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        /* The goal is to minimize the maximum number in the array */
        int s = 1, e = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(f(m, nums, maxOperations)) {
                ans = m;
                e = m - 1;
            }
            else s = m + 1;
        }
        return ans;
    }
};