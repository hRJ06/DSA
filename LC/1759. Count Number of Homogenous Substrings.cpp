class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length(), ans = 0, cnt = 0;
        int MOD = 1e9 + 7;
        for(int i = 0; i<n; i++) {
            if(i > 0 and s[i] == s[i - 1]) cnt++;
            else cnt = 1;
            (ans += cnt) %= MOD;
        }
        return ans;
    }
};