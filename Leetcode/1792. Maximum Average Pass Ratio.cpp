typedef pair<double, double> p;
class c {
public:
    bool operator()(p i, p j) {
        double di = ((i.first + 1) / (i.second + 1)) - (i.first / i.second);
        double dj = ((j.first + 1) / (j.second + 1)) - (j.first / j.second);
        return di < dj;
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0;
        int n = classes.size();
        priority_queue<p, vector<p>, c> pq;
        for(int i = 0; i<n; i++) {
            double pass = classes[i][0];
            double total = classes[i][1];
            pq.push({pass, total});
        }
        while(extraStudents--) {
            p top = pq.top();
            pq.pop();
            double pass = top.first + 1;
            double second = top.second + 1;
            pq.push({pass, second});
        }
        while(!pq.empty()) {
            p top = pq.top();
            pq.pop();
            double pass = top.first;
            double total = top.second;
            ans += (pass / total);
        }
        return ans / n;
    }
};