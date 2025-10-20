class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i<n; i++) {
            int ans = 0;
            for(int j = 0; j<n; j++) {
                if(i != j and grid[i][j]) ans++;
                if(ans != n - 1) continue;
                else return i;
            }
        }
        return -1;
    }
};
