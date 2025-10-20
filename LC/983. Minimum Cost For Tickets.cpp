class Solution {
private:
    vector<int> dp;
    int f(int index, int n, vector<int> &days, vector<int> &costs) {
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        int a = costs[0] + f(index + 1, n, days, costs);
        int j;
        for(j = index + 1; j<n and days[j] < days[index] + 7; j++);
        int b = costs[1] + f(j, n, days, costs);
        for(j = index + 1; j<n and days[j] < days[index] + 30; j++); 
        int c = costs[2] + f(j, n, days, costs);
        return dp[index] = min({a, b, c}); 
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.resize(n, -1);
        return f(0, n, days, costs);
    }
};