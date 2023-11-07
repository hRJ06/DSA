class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size(), ans = 0;
        vector<double> v(n);
        for(int i = 0;  i<n; i++)
            v[i]  = 1.0 * dist[i] / speed[i];
        sort(v.begin(),v.end());
        for(int i = 0; i<n; i++) {
            if(v[i] <= i) return i;
        }
        return n;
    }
};