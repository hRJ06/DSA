class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> workers;
        for(int i = 0; i<n; i++)
            workers.push_back({(wage[i] * 1.0) / quality[i], quality[i]});
        sort(workers.begin(),workers.end());
        priority_queue<int> pq;
        double ans = DBL_MAX, quality_total = 0;
        for(auto &i : workers) {
            double ratio = i.first;
            quality_total += i.second;
            pq.push(i.second);
            if(pq.size() > k) {
                quality_total -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) ans = min(ans,quality_total * ratio);
        }
        return ans;
    }
};