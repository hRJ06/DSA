class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<int>> mp;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        bool check = true;
        for(auto &i : mp) {
            vector<int> v = i.second;
            int s = v.size();
            for(int j = 0; j<s; j++) {
                ans.push_back(check ? v[s - j - 1] : v[j]);
            }
            check = !check;
        }
        return ans;
    }
};