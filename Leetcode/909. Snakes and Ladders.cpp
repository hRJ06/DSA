class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), index = 1;
        vector<pair<int, int>> store(n * n + 1);
        bool reverse = false;
        for(int i = n - 1; i>=0; i--) {
            for(int j = 0; j<n; j++) {
                store[index++] = {i, !reverse ? j : (n - 1) - j};
            }
            reverse = !reverse;
        }
        int step = 0;
        queue<int> q;
        vector<bool> v(n * n + 1, false);
        q.push(1);
        v[1] = true;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int top = q.front();
                q.pop();
                if(top != n * n) {
                    for(int next = top + 1; next<=min(top + 6, n * n); next++) {
                        auto [r, c] = store[next];
                        int destination = board[r][c] != -1 ? board[r][c] : next;
                        if(!v[destination]) {
                            v[destination] = true;
                            q.push(destination);
                        }
                    }
                }
                else return step;
            }
            step++;
        }
        return -1;
    }
};