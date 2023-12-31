class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        vector<pair<int,int>> v(26,{-1,-1});
        for(int i = 0; i<n; i++) {
            if(v[s[i] - 'a'].first != -1) {
                v[s[i] - 'a'].second = i;
            }
            else {
                v[s[i] - 'a'].first = i;
            }
        }
        int ans = -1;
        for(int i = 0; i<26; i++) {
            if(v[i].second != -1) {
                ans = max(ans,v[i].second - v[i].first - 1);   
            }
        }
        return ans;
    }
};
