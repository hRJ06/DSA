class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int n = profit.size(), m = worker.size(), j = 0;
        for(int i = 0; i<n; i++)
            v.push_back({difficulty[i], profit[i]});
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        int ans = 0, cur = 0;
        for(int i = 0; i<m; i++) {
            while(j < n and v[j].first <= worker[i]) 
                cur = max(cur, v[j++].second);
            ans += cur;
        }
        return ans;
    }
};