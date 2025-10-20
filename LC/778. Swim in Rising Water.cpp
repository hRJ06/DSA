class Solution {
private:
    int n;
    bool check(int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int dir[5] = {-1, 0, 1, 0, -1};
        set<pair<int, pair<int, int>>> s;
        vector<vector<bool>> v(n, vector<bool>(n, false));
        v[0][0] = true;
        s.insert({grid[0][0], {0, 0}});
        while(!s.empty()) {
            auto top = *(s.begin());
            s.erase(s.begin());
            int t = top.first;
            int r = top.second.first, c = top.second.second;
            if(r >= n - 1 and c >= n - 1) return t;
            for(int d = 0; d<4; d++) {
                int r_ = r + dir[d];
                int c_ = c + dir[d + 1];
                if(check(r_, c_) and !v[r_][c_]) {
                    s.insert({max(t, grid[r_][c_]), {r_, c_}});
                    v[r_][c_] = true;
                }
            }
        }
        return -1;
    }
};