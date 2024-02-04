class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto &i : t) mp[i]++;
        int i = 0, j = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
        int n = s.size();
        while(j < n) {
            if(mp[s[j]] > 0) counter--;
            mp[s[j]]--;
            j++;
            while(!counter) {
                if(j - i < minLen) {
                    minStart = i;
                    minLen = j - i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) counter++;
                i++;
            }
        }
        return minLen != INT_MAX ? s.substr(minStart,minLen) : "";
    }
};