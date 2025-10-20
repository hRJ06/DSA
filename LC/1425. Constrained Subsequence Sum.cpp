class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = nums[0];
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        for(int i = 1; i<n; i++) {
            while(!pq.empty() and i - pq.top().second > k) pq.pop();
            int x = max(nums[i],nums[i] + pq.top().first);
            pq.push({x,i});
            ans = max(ans,x);
        }
        return ans;
    }
};