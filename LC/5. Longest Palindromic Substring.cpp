class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return s;
        int start = 0, len = 1;
        for(int i = 0; i<n; i++) {
            int l = i, r = i;
            while(l >= 0 and r < n) {
                if(s[l] != s[r]) break;
                else {
                    l--;
                    r++;
                }
            }
            int cur = r - l - 1;
            if(cur > len) {
                len = cur;
                start = l + 1;
            }
        }
        for(int i = 0; i<n; i++) {
            int l = i, r = i + 1;
            while(l >= 0 and r < n) {
                if(s[l] != s[r]) break;
                else {
                    l--;
                    r++;
                }
            }
            int cur = r - l - 1;
            if(cur > len) {
                len = cur;
                start = l + 1;
            }
        }
        return s.substr(start,len);
    }
};