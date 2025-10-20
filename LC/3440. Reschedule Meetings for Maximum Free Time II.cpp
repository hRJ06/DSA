class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int start = 0, n = startTime.size();
        vector<int> gap;
        for(int i = 0; i<n; i++) {
            gap.push_back(startTime[i] - start);
            start = endTime[i];
        }
        gap.push_back(eventTime - start);
        int m = gap.size();
        vector<int> largest(m, 0);
        for(int i = m - 2; i>=0; i--) {
            largest[i] = max(largest[i + 1], gap[i + 1]);
        }
        int left = 0, ans = 0;
        for(int i = 0; i<m - 1; i++) {
            int p = endTime[i] - startTime[i];
            if(p <= max(left, largest[i + 1])) 
                ans = max(ans, gap[i] + gap[i + 1] + p);
            else
                ans = max(ans, gap[i] + gap[i + 1]);
            left = max(left, gap[i]);
        }
        return ans;
    }
};