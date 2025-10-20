class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        function<int()> f = [&]() -> int {
            int s = 0, e = n - 1, ans = -1;
            while(s <= e) {
                int m = s + (e - s) / 2;
                if(nums[m] < target)
                    s = m + 1;
                else if(nums[m] > target)
                    e = m - 1;
                else {
                    ans = m;
                    e = m - 1;
                }
            }
            return ans;
        };
        function<int()> s = [&]() -> int {
            int s = 0, e = n - 1, ans = -1;
            while(s <= e) {
                int m = s + (e - s) / 2;
                if(nums[m] < target)
                    s = m + 1;
                else if(nums[m] > target)
                    e = m - 1;
                else {
                    ans = m;
                    s = m + 1;
                }
            }
            return ans;
        };
        return {f(),s()};
    }
};