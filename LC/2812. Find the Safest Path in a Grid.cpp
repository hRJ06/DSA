class Solution {
private:
    vector<int> dir = {-1, 0, 1, 0, -1};
    bool valid(int n,int r,int c,vector<vector<bool>> &vis) {
        if(r < 0 or c < 0 or r >= n or c >= n or vis[r][c]) return false;
        return true;
    }
    bool safe(vector<vector<int>> &distance, int dist) {
        int n = distance.size();
        queue<pair<int,int>> q;
        if(distance[0][0] < dist) return false;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push({0,0});
        vis[0][0] = true;
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            int r = top.first, c = top.second;
            if(r == n - 1 and c == n - 1) return true;
            for(int i = 0; i<4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];
                if(valid(n,nr,nc,vis)) {
                    if(distance[nr][nc] >= dist) {
                        vis[nr][nc] = true;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
    
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<vector<int>> distance(n, vector<int>(n, -1));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]) {
                    vis[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        int len = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int r = top.first, c = top.second;
                distance[r][c] = len;
                for(int i = 0; i<4; i++) {
                    int nr = r + dir[i];
                    int nc = c + dir[i + 1];
                    if(valid(n,nr,nc,vis)) {
                        vis[nr][nc] = true;
                        q.push({nr,nc});
                    }
                }
            }
            len++;
        }
        int low = 0, high = len;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(safe(distance,mid)) {
                ans = mid;
                low = mid + 1;
            }
            else 
                high = mid - 1;
        }
        return ans;
    }
};