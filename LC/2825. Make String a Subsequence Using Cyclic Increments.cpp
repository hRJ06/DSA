class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i = 0, j = 0;
        int n = s.length(), m = t.length();
        while(i < n and j < m) {
            if(s[i] != t[j]) {
                int d = (t[j] - s[i] + 26) % 26;
                if(d != 1)
                    i++;
                else {
                    i++;
                    j++;
                }
            }
            else {
                i++;
                j++;
            }
        }
        return j == m;
    }
};