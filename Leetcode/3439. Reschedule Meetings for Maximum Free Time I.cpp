class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int start = 0;
        vector<int> gap;
        for(int i = 0; i<n; i++) {
            gap.push_back(startTime[i] - start);
            start = endTime[i];
        }
        gap.push_back(eventTime - start);
        int ans = INT_MIN, cur = 0, m = gap.size();
        for(int i = 0; i<min(m, k + 1); i++) {
            cur += gap[i];
        }
        ans = max(ans, cur);
        for(int i = 0, j = k + 1; j<m; i++, j++) {
            cur -= gap[i];
            cur += gap[j];
            ans = max(ans, cur);
        }
        return ans;
    }
};
