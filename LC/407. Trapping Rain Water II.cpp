typedef pair<int, pair<int,int>> p;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<bool>> v(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            v[i][0] = v[i][n - 1] = true;
        }
        for(int i = 0; i<n; i++) {
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[m - 1][i], {m - 1, i}});
            v[0][i] = v[m - 1][i] = true; 
        }
        int ans = 0;
        vector<int> d = {-1, 0, 1, 0, -1};
        while(!pq.empty()) {
            p top = pq.top();
            pq.pop();
            int height = top.first;
            int r = top.second.first, c = top.second.second;
            for(int k = 0; k<4; k++) {
                int nr = r + d[k];
                int nc = c + d[k + 1];
                if(nr >= 0 and nr < m and nc >= 0 and nc < n and !v[nr][nc]) {
                    ans += max(0, height - heightMap[nr][nc]);
                    v[nr][nc] = true;
                    pq.push({max(height, heightMap[nr][nc]), {nr, nc}});
                }
            }
        }
        return ans;
    }
};