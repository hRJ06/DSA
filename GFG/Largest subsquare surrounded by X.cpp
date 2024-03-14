class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        vector<vector<int>> R(n, vector<int>(n)), C(n, vector<int>(n));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                R[i][j] = a[i][j] != 'X' ? 0 : (!j ? 1 : 1 + R[i][j - 1]); 
                C[j][i] = a[j][i] != 'X' ? 0 : (!j ? 1 : 1 + C[j - 1][i]); 
            }
        }
        int ans = 0;
        for(int i = n - 1; i>=0; i--) {
            for(int j = n - 1; j>=0; j--) {
                int x = min(R[i][j], C[i][j]);
                while(x > ans) {
                    if(R[i - x + 1][j] >= x and C[i][j - x + 1] >= x) {
                        ans = x;
                        break;
                    }
                    else
                        x--;
                }
            }
        }
        return ans;
    }
};