class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end());
            /* First merge overlapping intervals */
            vector<vector<int>> overlapped;
            int n = meetings.size();
            for(int i = 0; i<n; i++) {
                if(overlapped.empty() or meetings[i][0] > overlapped.back()[1]) {
                    overlapped.push_back(meetings[i]);
                }
                else {
                    overlapped.back()[1] = max(overlapped.back()[1], meetings[i][1]);
                }
            }
            int ans = overlapped[0][0] - 1;
            int m = overlapped.size();
            for(int i = 0; i<m - 1; i++) {
                ans += overlapped[i + 1][0] - overlapped[i][1] - 1;
            }
            ans += days - overlapped[m - 1][1];
            return ans;
        }
    };