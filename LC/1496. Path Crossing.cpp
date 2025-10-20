class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int,int>> v;
        int x = 0, y = 0;
        v.push_back({x,y});
        for(auto &i : path) {
            if(i == 'N') x++;
            else if(i == 'S') x--;
            else if(i == 'E') y++;
            else y--;
            v.push_back({x,y});
        }
        set<pair<int,int>> s(v.begin(),v.end());
        return v.size() == s.size() ? false : true;
    }
};