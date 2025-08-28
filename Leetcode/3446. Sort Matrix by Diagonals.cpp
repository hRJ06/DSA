class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, multiset<int>> mp;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp[i - j].insert(grid[i][j]);
            }
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(i >= j) {
                    auto it = --mp[i - j].end();
                    ans[i][j] = *(it);
                    mp[i - j].erase(it);
                }
                else {
                    ans[i][j] = *(mp[i - j].begin());
                    mp[i - j].erase(mp[i - j].begin());
                }
            }
        }
        return ans;
    }
};