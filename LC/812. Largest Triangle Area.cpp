class Solution {
private:
    double f(vector<int> &p1, vector<int> &p2) {
        int d1 = pow(p1[0] - p2[0], 2);
        int d2 = pow(p1[1] - p2[1], 2);
        return sqrt(d1 + d2);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = points.size();
        for(int i = 0; i<n - 2; i++) {
            for(int j = i + 1; j<n - 1; j++) {
                for(int k = j + 1; k<n; k++) {
                    double a = f(points[i], points[j]);
                    double b = f(points[j], points[k]);
                    double c = f(points[k], points[i]);
                    double s = (a + b + c) / 2.0;
                    double areaSq = s * (s - a) * (s - b) * (s - c);
                    ans = max(ans, sqrt(areaSq));
                }
            }
        }
        return ans;
    }
};