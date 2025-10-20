class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c]) {
                    perimeter += 4;
                    if(r > 0 and grid[r-1][c])
                        perimeter -= 2;
                    if(c > 0 and grid[r][c-1]) 
                        perimeter -= 2;
                }
            }
        }  
        return perimeter;
    }
};