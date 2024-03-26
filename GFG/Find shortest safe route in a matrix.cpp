class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
        int dir[5] = {-1, 0, 1, 0, -1};
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(!mat[i][j]) {
                    for(int k = 0; k<4; k++) {
                        int r = i + dir[k];
                        int c = j + dir[k + 1];
                        if(r >= 0 and r < m and c >= 0 and c < n) mat[r][c] = -1;
                    }
                }
            }
        }
        for(auto &i : mat) {
            for(auto &j : i) {
                if(j == -1)
                    j = 0;
            }
        }
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++) {
            if(mat[i][0]) {
                q.push({i,0});
                vis[i][0] = true;
            }
        }
        int ans = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(c == n - 1) return ans;
                for(int k = 0; k<4; k++) {
                    int nr = r + dir[k];
                    int nc = c + dir[k + 1];
                    if(nr >= 0 and nr < m and nc >= 0 and nc < n and mat[nr][nc] and !vis[nr][nc]) {
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};