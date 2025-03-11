class Solution {
    public:
        int numberOfSubstrings(string s) {
            int i = 0, j = 0;
            unordered_map<char, int> mp;
            int n = s.length(), ans = 0;
            while(j < n) {
                mp[s[j]]++;
                if(mp.size() >= 3) {
                    while(mp.size() >= 3) {
                        ans += n - j;
                        mp[s[i]]--;
                        if(!mp[s[i]]) mp.erase(s[i]);
                        i++;
                    }
                }
                j++;
            }
            return ans;
        }
    };