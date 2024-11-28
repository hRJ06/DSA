class Solution {
private:
    int f(int i, int j, int m, int n) {
        return i >= 0 and i < m and j >= 0 and j < n;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<pair<int,pair<int,int>>> s;
        s.insert({0, {0, 0}});
        int d[5] = {-1, 0, 1, 0, -1};
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[0][0] = 0;
        while(!s.empty()) {
            auto top = *(s.begin());
            s.erase(s.begin());
            int cost = top.first;
            int r = top.second.first, c = top.second.second;
            for(int i = 0; i<4; i++) {
                int nr = r + d[i];
                int nc = c + d[i + 1];
                if(f(nr, nc, m, n) and (cost + grid[nr][nc] < distance[nr][nc])) {
                    if(s.find({distance[nr][nc], {nr, nc}}) != s.end()) {
                        s.erase({distance[nr][nc], {nr, nc}});
                    }
                    distance[nr][nc] = cost + grid[nr][nc];
                    s.insert({distance[nr][nc], {nr, nc}});
                }
            }
        }
        return distance[m - 1][n - 1];
    }
};