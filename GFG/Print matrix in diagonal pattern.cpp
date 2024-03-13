class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat) {
        bool flag = false;
        int dig = 0, n = mat.size();
        vector<int> ans;
        while(dig <= 2 * n - 2){
            if(flag){
                for(int i = 0; i<=dig; i++){
                    if(max(dig-i, i) < n)
                        ans.push_back(mat[i][dig-i]);
                }
                flag = false;
            }
            else{
                for(int j = 0; j<=dig; j++){
                    if(max(dig-j, j) < n) {
                        ans.push_back(mat[dig-j][j]);
                    }
                }
                flag = true;
            }
            dig++;
        }
        return ans;
    }
};