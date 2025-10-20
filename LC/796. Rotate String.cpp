class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length(), n = goal.length();
        if(m != n) return false;
        while(m--) {
            string rest = s.substr(1) + s[0];
            if(rest == goal) return true;
            s = rest;
        }
        return false;
    }
};