class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        vector<int> ans;
        int n = matrix.size();
        map<int,vector<int>> mp;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                mp[i + j].push_back(matrix[i][j]);
            }
        }
        for(auto &i : mp) {
            for(auto &j : i.second) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};