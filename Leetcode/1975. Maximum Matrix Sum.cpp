typedef long long ll;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), mini = INT_MAX;
        vector<int> negative;
        ll total = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(matrix[i][j] < 0) negative.push_back(matrix[i][j]);
                else total += matrix[i][j];
                mini = min(mini, abs(matrix[i][j]));
            }
        }
        ll negative_total = accumulate(negative.begin(), negative.end(), 0LL);
        total += -1 * negative_total;
        if(negative.size() & 1) total -= (2 * mini);
        return total;
    }
};