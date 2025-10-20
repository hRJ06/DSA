class Solution {
private:
    void dfs(int row, int col, int m, int n, int dir, vector<vector<int>> &checkSet) {
        if(row < 0 or row >= m or col < 0 or col >= n or checkSet[row][col] == 1 or checkSet[row][col] == 2) return;
        checkSet[row][col] = 3;
        if(dir == 1) dfs(row - 1, col, m, n, 1, checkSet);
        else if(dir == 2) dfs(row + 1, col, m, n, 2, checkSet);
        else if(dir == 3) dfs(row, col + 1, m, n, 3, checkSet);
        else dfs(row, col - 1, m, n, 4, checkSet);
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> checkSet(m, vector<int>(n, 0));
        for(auto &i : walls) checkSet[i[0]][i[1]] = 1;
        for(auto &i : guards) checkSet[i[0]][i[1]] = 2;
        for(auto &i : guards) {
            int r = i[0], c = i[1];
            dfs(r - 1, c, m, n, 1, checkSet);
            dfs(r + 1, c, m, n, 2, checkSet);
            dfs(r, c + 1, m, n, 3, checkSet);
            dfs(r, c - 1, m, n, 4, checkSet);
        }
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(!checkSet[i][j]) ans++;
            }
        }
        return  ans;
    }
};