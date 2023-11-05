class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        for(auto &i : nums) mp[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto &i : mp) pq.push({i.second,i.first});
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};