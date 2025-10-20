class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> v;
        int n = names.size();
        for(int i = 0; i<n; i++) v.push_back(i);
        sort(v.begin(), v.end(), [&](int i, int j) {
            return heights[i] > heights[j];
        });
        vector<string> ans;
        for(int i = 0; i<n; i++)
            ans.push_back(names[v[i]]);
        return ans;
    }
};
