class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                ans[j][i] = box[m - 1 - i][j];
            }
        }
        /* 
            # -> Stone
            * -> Obstacle 
            . -> Empty
        */
        for(int col = 0; col<m; col++) {
            int last_place_to_fall = n - 1;
            for(int row = n - 1; row>=0; row--) {
                if(ans[row][col] == '*') {
                    last_place_to_fall = row - 1;
                }
                else if(ans[row][col] == '#') {
                    if(row != last_place_to_fall) {
                        ans[row][col] = '.';
                        ans[last_place_to_fall][col] = '#';
                    }
                    last_place_to_fall--;
                }
            }
        }
        return ans;
    }
};