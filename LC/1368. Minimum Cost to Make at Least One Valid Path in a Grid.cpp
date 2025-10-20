typedef pair<int, int> p;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<p> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        set<pair<int, p>> s;
        s.insert({0, {0, 0}});
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> d(m, vector<int>(n, INT_MAX));
        d[0][0] = 0;
        while(!s.empty()) {
            auto top = *(s.begin());
            s.erase(s.begin());
            int cost = top.first;
            int r = top.second.first, c = top.second.second;
            for(int k = 0; k<=3; k++) {
                int nr = r + dir[k].first, nc = c + dir[k].second;
                int ncost = grid[r][c] - 1 != k ? cost + 1 : cost;
                if(nr >= 0 and nr < m and nc >= 0 and nc < n and d[nr][nc] > ncost) {
                    auto find = s.find({d[nr][nc], {nr, nc}});
                    if(find != s.end()) s.erase(find);
                    d[nr][nc] = ncost;
                    s.insert({d[nr][nc], {nr, nc}});
                }
            }
        }
        return d[m - 1][n - 1];
    }
};