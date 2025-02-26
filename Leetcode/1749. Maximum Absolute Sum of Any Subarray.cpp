class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int ans_1 = INT_MAX, ans_2 = INT_MIN;
            int total = 0;
            for(int n : nums) {
                total += n;
                ans_2 = max(ans_2, total);
                if(total < 0) total = 0;
            }
            total = 0;
            for(int n : nums) {
                total += n;
                ans_1 = min(ans_1, total);
                if(total > 0) total = 0;
            }
            return max(abs(ans_1), abs(ans_2));
        }
    };