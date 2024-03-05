class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.length() - 1;
        char ch = '0';
        while(i < j and s[i] == s[j]) {
            ch = s[i];
            while(i < j and s[i] == ch) i++;
            while(i < j and s[j] == ch) j--;
        }
        if(s[i] != ch) return j - i + 1;
        else return 0;
    }
};