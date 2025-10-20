class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> s;
        int x = 0, y = 0, ans = 0;
        for(auto &i : obstacles)
            s.insert({i[0], i[1]});
        vector<pair<int,int>> directions = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}}; /* N, W, E, S */
        int dir = 0; /* Initial North */
        for(auto &i : commands) {
            if(i == -2) {
                switch (dir) {
                    case 0:
                        dir = 1;
                        break;
                    case 1:
                        dir = 3;
                        break;
                    case 2:
                        dir = 0;
                        break;
                    case 3:
                        dir = 2;
                        break;
                }
            }
            else if(i == -1) {
                switch (dir) {
                    case 0:
                        dir = 2;
                        break;
                    case 1:
                        dir = 0;
                        break;
                    case 2:
                        dir = 3;
                        break;
                    case 3:
                        dir = 1;
                        break;
                }
            }
            else {
                while(i-- and s.find({x + directions[dir].first, y + directions[dir].second}) == s.end()) {
                    x += directions[dir].first;
                    y += directions[dir].second;
                }
                ans = max(ans, x * x + y * y);
                            
            }
        }
        return ans;
    }
};