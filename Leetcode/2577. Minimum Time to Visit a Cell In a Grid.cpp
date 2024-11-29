class Solution {
private:
    int f(int r, int c, int m, int n) {
        return r >= 0 and r < m and c >= 0 and c < n;
    }
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[0][1] > 1 and grid[1][0] > 1) return -1;
        set<pair<int, pair<int,int>>> s;
        s.insert({0, {0, 0}});
        vector<vector<int>> t(m, vector<int>(n, INT_MAX));
        int d[5] = {-1, 0, 1, 0, -1};
        t[0][0] = 0;
        while(!s.empty()) {
            auto top = *(s.begin());
            s.erase(s.begin());
            int time = top.first;
            int r = top.second.first, c = top.second.second;
            for(int i = 0; i<4; i++) {
                int nr = r + d[i], nc = c + d[i + 1];
                if(!f(nr, nc, m, n)) continue;
                int nt = max(grid[nr][nc] + ((grid[nr][nc] - time) & 1 ? 0 : 1), time + 1);
                if(nt < t[nr][nc]) {
                    if(s.find({t[nr][nc], {nr, nc}}) != s.end()) {
                        s.erase({t[nr][nc], {nr, nc}});
                    }
                    t[nr][nc] = nt;
                    s.insert({t[nr][nc], {nr, nc}});
                }
            }
        }
        return t[m - 1][n - 1];
    }
};