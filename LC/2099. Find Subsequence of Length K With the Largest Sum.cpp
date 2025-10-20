typedef pair<int, int> p;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<p, vector<p>, greater<p>> pq;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(pq.size() < k) {
                pq.push({nums[i], i});
            } 
            else if(nums[i] > pq.top().first) {
                pq.pop();
                pq.push({nums[i], i});
            }
        }
        vector<p> v;
        while(!pq.empty()) {
            v.push_back(pq.top());
            pq.pop();
        }
        sort(v.begin(), v.end(), [&](p a, p b) {
            return a.second < b.second;
        });
        vector<int> ans;
        for(auto &i : v) {
            ans.push_back(i.first);
        }
        return ans;
    }
};
