class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n = tasks.size(), m = processorTime.size();
        int ans = INT_MIN, a = n - 1;
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end());
        for(int i = 0; i<m; i++,a-=4) ans = max(ans,processorTime[i] + tasks[a]);
        return ans;
    }
};