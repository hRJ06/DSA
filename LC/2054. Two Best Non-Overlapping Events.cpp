typedef pair<int, pair<int, int>> p;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events));
        priority_queue<p, vector<p>, greater<p>> pq;
        int maxValue = 0, ans = 0;
        for(auto &i : events) {
            while(!pq.empty() and (pq.top().first < i[0])) {
                maxValue = max(maxValue, pq.top().second.second);
                pq.pop();
            }
            ans = max(ans, maxValue + i[2]);
            pq.push({i[1], {i[0], i[2]}});
        } 
        return ans;
    }
};