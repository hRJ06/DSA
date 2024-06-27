class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        unordered_set<int> s;
        for(auto &i : edges) {
            s.insert(i[0]);
            s.insert(i[1]);
            mp[i[0]]++;
            mp[i[1]]++;
        }
        for(auto &i : mp) 
            if(i.second >= s.size() - 1) return i.first;
        return -1;
    }
};