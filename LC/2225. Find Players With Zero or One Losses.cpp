class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,vector<int>> mp;
        set<int> s;
        for(auto &i : matches) {
            mp[i[1]].push_back(i[0]);
            s.insert(i[0]);
            s.insert(i[1]);
        }
        vector<int> a, b;
        for(auto &i : s) {
            if(!mp.count(i)) a.push_back(i);
            if(mp.count(i) and mp[i].size() == 1) b.push_back(i);
        }
        vector<vector<int>> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};