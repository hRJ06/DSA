class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(matrix[i][j] and i > 0)
                    matrix[i][j] += matrix[i - 1][j];
            }
            vector<int> height = matrix[i];
            sort(height.begin(),height.end(),greater<int>());
            for(int i = 0; i<n; i++) {
                int b = i + 1;
                int h = height[i];
                ans = max(ans,b * h);
            }
        }
        return ans; 
    }
};