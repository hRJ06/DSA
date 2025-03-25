typedef pair<int,int> p;
class Solution {
private:
    bool h(vector<vector<int>> &rectangles) {
        int n = rectangles.size();
        vector<p> v;
        for(int i = 0; i<n; i++) {
            v.push_back({rectangles[i][1], rectangles[i][3]});
        }
        sort(v.begin(), v.end());
        int ans = 0, end = v[0].second;
        for(int i = 1; i<v.size(); i++) {
            if(v[i].first >= end) {
                ans++;
                end = v[i].second;
            }
            else end = max(end, v[i].second);
        }
        return ans >= 2;
    }
    bool v(vector<vector<int>> &rectangles) {
            int n = rectangles.size();
            vector<p> v;
            for(int i = 0; i<n; i++) {
                v.push_back({rectangles[i][0], rectangles[i][2]});
            }
            sort(v.begin(), v.end());
            int ans = 0, end = v[0].second;
            for(int i = 1; i<v.size(); i++) {
                if(v[i].first >= end) {
                    ans++;
                    end = v[i].second;
                }
                else end = max(end, v[i].second);
            }
            return ans >= 2;
        }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return h(rectangles) or v(rectangles);
    }
};