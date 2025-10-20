class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int> mp;
        for(auto &i : s) {
            mp[i]++;
        }
        for(auto &i : t) {
            mp[i]--;
        }
        int ans = 0;
        for(auto &i : mp) {
            if(i.second > 0) ans += i.second;
        }
        return ans;
    }
};