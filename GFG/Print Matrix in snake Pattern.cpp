class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        bool f = 1;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                ans.push_back(f ? matrix[i][j] : matrix[i][n - j - 1]);
            }
            f = !f;
        }
        return ans;
    }
};