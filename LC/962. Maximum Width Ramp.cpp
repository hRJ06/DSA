class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        for(int i = 0; i<n; i++) {
            if(s.empty() or nums[i] < nums[s.top()])
                s.push(i);
        }
        int ans = 0;
        /* Optimal to start from rightmost index */
        for(int i = n - 1; i>=0; i--) {
            /* [6,0,8,2,1,5] */
            /* If 5 at index 5 doesn't go with 0 at index 1 (suppose), then for sure it won't go with 6 at index, so less computation */
            /* If 5 at index 5 goes with 0 at index 1 it may match with 6 at index 0 */
            while(!s.empty() and nums[i] >= nums[s.top()]) {
                ans = max(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
};