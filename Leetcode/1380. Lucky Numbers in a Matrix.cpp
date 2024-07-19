class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,int> row, col;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i<m; i++)
            row[i] = INT_MAX;
        for(int j = 0; j<n; j++)
            col[j] = INT_MIN;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                row[i] = min(matrix[i][j], row[i]);
                col[j] = max(matrix[i][j], col[j]);
            }
        }
        vector<int> ans;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(row[i] == matrix[i][j] and col[j] == matrix[i][j])
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};
