class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> chosen;
        sort(queries.begin(), queries.end());
        int n = nums.size(), m = queries.size();
        int j = 0, ans = 0;
        for(int i = 0; i<n; i++) {
            int index = i;
            while(j < m and queries[j][0] == index) {
                pq.push(queries[j][1]);
                j++;
            }
            while(chosen.size() and chosen.top() < index) {
                chosen.pop();
            }
            nums[i] -= chosen.size();
            while(nums[i] > 0 and pq.size() and pq.top() >= i) {
                nums[i]--;
                ans++;
                chosen.push(pq.top());
                pq.pop();
            }
            if(nums[i] > 0) return -1;
        }  
        return m - ans;
    }
};