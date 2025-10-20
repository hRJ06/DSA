class Solution {
private:
    int find(int i,int n,vector<vector<int>> &jobs,int target) {
        int ans = -1, s = i, e = n - 1;
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(jobs[m][0] >= target) {
                ans = m;
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }
        return ans != -1 ? ans : n;
    }
    int f(int i,vector<vector<int>> &jobs,vector<int> &dp,int n) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int a = f(i + 1,jobs,dp,n);
        int b = jobs[i][2] + f(find(i + 1,n,jobs,jobs[i][1]),jobs,dp,n);
        return dp[i] = max(a,b);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> dp(n,-1);
        vector<vector<int>> jobs(n);
        for(int i = 0; i<n; i++) {
            jobs[i] = {startTime[i],endTime[i],profit[i]};
        }
        sort(jobs.begin(),jobs.end());
        return f(0,jobs,dp,n);
    }
};