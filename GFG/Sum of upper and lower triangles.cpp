class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        int l = 0, u = 0;
        for(int i = 0; i<n; i++) {
            for(int j = n - 1; j>=i; j--) {
                u += matrix[i][j];
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<=i; j++) {
                l += matrix[i][j];
            }
        }
        return {u,l};
        
    }
};