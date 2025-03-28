typedef vector<int> v;
class Solution {
private:
    bool ok(int i, int j, int m, int n, vector<vector<bool>> &vis) {
        return i >= 0 and i < m and j >= 0 and j < n and !vis[i][j];
    }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sortedQ;
        int Q = queries.size();
        for(int i = 0; i<Q; i++) {
            sortedQ.push_back({queries[i], i});
        }
        sort(sortedQ.begin(), sortedQ.end());
        int points = 0;
        priority_queue<v, vector<v>, greater<>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;
        vector<int> dir = {-1, 0, 1, 0, -1};
        v ans(Q);
        for(int i = 0;  i<Q; i++) {
            int val = sortedQ[i][0];
            int index = sortedQ[i][1];
            while(!pq.empty() and pq.top()[0] < val) {
                v top = pq.top();
                pq.pop();
                points++;
                for(int d = 0; d<4; d++) {
                    int i_ = top[1] + dir[d];
                    int j_ = top[2] + dir[d + 1];
                    if(ok(i_, j_, m, n, vis)) {
                        vis[i_][j_] = true;
                        pq.push({grid[i_][j_], i_, j_});
                    }
                }
            }
            ans[index] = points;
        }
        return ans;
    }
};