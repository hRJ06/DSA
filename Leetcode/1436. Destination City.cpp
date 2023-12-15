class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,bool> mp;
        for(auto &i : paths) mp[i[0]] = true;
        for(auto &i : paths) if(!mp.count(i[1])) return i[1];
        return "";
    }
};