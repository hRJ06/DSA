typedef pair<int, int> p;
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n, -1);
        unordered_map<int, vector<p>> mp;
        for(int index = 0; index<n; index++) {
            int i = queries[index][0], j = queries[index][1];
            if((i == j) or ((heights[i] > heights[j]) and (i > j)) or ((heights[j] > heights[i]) and (j > i))) ans[index] = max(i, j);
            else {
                mp[max(i, j)].push_back({max(heights[j], heights[i]), index});
            }
        }
        priority_queue<p, vector<p> , greater<p>> pq;
        int m = heights.size();
        for(int i = 0; i<m; i++) {
            while(!pq.empty() and heights[i] > pq.top().first) {
                auto [_, qi] = pq.top();
                pq.pop();
                ans[qi] = i;
            }
            for(auto &i : mp[i]) {
                pq.push(i);
            }
        }
        return ans;
    }
};