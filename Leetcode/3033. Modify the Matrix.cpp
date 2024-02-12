class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        unordered_map<int,int> mp;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp[j] = max(mp[j],matrix[i][j]);
            }
        }
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(matrix[i][j] == -1) matrix[i][j] = mp[j];
            }
        }
        return matrix;
    }
};