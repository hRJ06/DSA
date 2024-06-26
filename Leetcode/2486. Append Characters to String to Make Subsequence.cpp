class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length(), m = t.length(), j = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == t[j]) j++;
            if(j == m) return 0;
        }
        return m - j;
    }
};