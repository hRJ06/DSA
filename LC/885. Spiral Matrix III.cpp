class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        int step = 1, dir = 0;
        ans.push_back({rStart, cStart});
        while(ans.size() < rows * cols) {
            for(int i = 0; i<step; i++) {
                rStart += directions[dir][0];
                cStart += directions[dir][1];
                if(rStart >= 0 and rStart < rows and cStart >= 0 and cStart < cols) 
                    ans.push_back({rStart, cStart});
            }
            dir = (dir + 1) % 4;
            if(!dir or dir == 2) 
                step++;
        }
        return ans;
    }
};
