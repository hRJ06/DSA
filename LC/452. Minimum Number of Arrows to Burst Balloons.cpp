class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int> a,vector<int> b) {
            return a[1] < b[1];
        });
        int ans = 1;
        int prev = points[0][1], n = points.size();
        for(int i = 1; i<n; i++) {
            if(points[i][0] > prev) {
                ans++;
                prev = points[i][1];
            }
        }   
        return ans;
    }
};