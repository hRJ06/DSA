/* EXPLANATION - https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/solutions/4152401/minimum-number-of-operations-to-make-array-continuous-c-sorting/ */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> s(nums.begin(),nums.end());
        vector<int> v(s.begin(),s.end());
        int m = v.size(), length = INT_MIN, end = 0;
        for(int i = 0; i<m; i++) {
            while(end < m and v[end] < v[i] + n) end++;
            length = max(length,end - i);
        }
        return n - length;
    }
};