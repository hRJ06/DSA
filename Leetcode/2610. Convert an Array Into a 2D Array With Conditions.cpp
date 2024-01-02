class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        int r = 0, i = 0;
        for(auto &i : nums) {
            mp[i]++;
            r = max(r,mp[i]);
        }
        vector<vector<int>> ans(r);
        while(mp.size() > 0) {
            for(auto &j : mp) ans[i].push_back(j.first);
            for(auto &j : ans[i])
                if(!--mp[j]) mp.erase(j);
            i++;
        }
        return ans;
    }
};