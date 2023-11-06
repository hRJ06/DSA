class Solution{
private:
    bool f(int i,int j,int n,int m) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
        vector<int> ans;
        vector<int> dX1 = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dY1 = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<int> dX2 = {-2, -2, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2};
        vector<int> dY2 = {-2, -1, 0, 1, 2, -2, 2, -2, 2, -2, 2, -2, -1, 0, 1, 2};
        for(int i = 0; i<q; i++) {
            int r = queries[i][1], c = queries[i][2];
            int total = 0;
            if(queries[i][0] == 1) {
                for(int k = 0; k<8; k++) {
                    int nr = r + dX1[k];
                    int nc = c + dY1[k];
                    if(f(nr,nc,n,m)) total += mat[nr][nc];
                }
            }
            else {
                for(int k = 0; k<16; k++) {
                    int nr = r + dX2[k];
                    int nc = c + dY2[k];
                    if(f(nr,nc,n,m)) total += mat[nr][nc];
                }
            }
            ans.push_back(total);
        }
        return ans;

    }
};