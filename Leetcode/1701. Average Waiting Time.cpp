class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int wait = customers[0][0], n = customers.size();
        for(int i = 0; i<n; i++) {
            int arrival = customers[i][0], time = customers[i][1];
            wait = max(wait, arrival);
            wait = wait + time;
            ans += (wait - arrival);
        }
        return (1.0 * ans) / n;
    }
};
