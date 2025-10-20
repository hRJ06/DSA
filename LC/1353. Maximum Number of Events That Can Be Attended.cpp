class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int day = -1, ans = 0, index = 0, n = events.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        while(!pq.empty() || index < n) {
            if(pq.empty()) {
                day = events[index][0];
            }
            while(index < n and events[index][0] <= day) {
                pq.push(events[index][1]);
                index++;
            }
            pq.pop();
            ans++;
            day++;
            while(!pq.empty() and pq.top() < day) {
                pq.pop();
            }
        }
        return ans;
    }
};