class Solution {
private:
    int f(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0, ans = 0;
        while (j < n) {
            mp[nums[j]]++;
            while (i <= j and mp.size() > k) {
                if (!(--mp[nums[i]]))
                    mp.erase(nums[i]);
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k - 1);
    }
};