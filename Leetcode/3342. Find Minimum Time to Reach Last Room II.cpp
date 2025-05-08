typedef pair<int, pair<bool, pair<int,int>>> p;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<p, vector<p>, greater<p>> pq; /* {t, {i, j}} */
        pq.push({0, {true, {0, 0}}});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> dir = {-1, 0, 1, 0, -1};
        while(!pq.empty()) {
            p top = pq.top();
            pq.pop();
            int time = top.first;
            bool isFirst = top.second.first;
            int x = top.second.second.first;
            int y = top.second.second.second;
            if(x == m - 1 and y == n - 1) return time;
            for(int i = 0; i<4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                if(nx >= 0 and nx < m and ny >= 0 and ny < n and !vis[nx][ny]) {
                    int t_ng = max(time + (isFirst ? 1 : 2), moveTime[nx][ny] + (isFirst ? 1 : 2));
                    pq.push({t_ng, {!isFirst, {nx, ny}}});
                    vis[nx][ny] = true;
                }
            }
        }
        return -1;
    }
};