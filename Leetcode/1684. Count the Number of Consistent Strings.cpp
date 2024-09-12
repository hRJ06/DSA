class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_set<char> s(allowed.begin(), allowed.end());
        for(auto &i : words) {
            bool flag = true;
            for(auto &j : i) {
                if(s.find(j) == s.end()) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};