class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int s = 0, c = 0;
                for(int x = i - 1; x<=i + 1; x++) {
                    for(int y = j - 1; y<=j + 1; y++) {
                        if(x >= 0 and x < m and y >= 0 and y < n) {
                            s += img[x][y];
                            c++;
                        }
                    }
                }
                ans[i][j] = s / c;
            }
        }
        return ans;
    }
};