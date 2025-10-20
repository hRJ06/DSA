class Solution {
private:
    void f(string &s) {
        int i = s.length() - 1;
        while(i >= 0 and s[i] != '0') {
            s[i] = '0';
            i--;
        }
        if(i < 0) s = '1' + s;
        else s[i] = '1';
    }
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.length() > 1) {
            int n = s.length();
            if(s[n - 1] != '0') f(s);
            else s.pop_back();
            ans++;
        }
        return ans;
    }
};