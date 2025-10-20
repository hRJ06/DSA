class Solution {
public:
    int maxSum(vector<int>& nums) {
        int large = INT_MIN, total = 0;
        unordered_set<int> s(begin(nums), end(nums));
        for(auto &i : s) {
            if(i > 0) total += i;
            large = max(large, i);
        }
        if(large >= 0) return total;
        return large;
    }
};