class Solution {
public:
    int maxScore(string s) {
        int one = 0, n = s.length();
        for(int i = 0; i<n; i++) {
            if(s[i] != '0') one++;
        }
        int ans = INT_MIN, zero = 0;
        for(int i = 0; i<n - 1; i++) {
            if(s[i] != '0') one--;
            else zero++;
            ans = max(ans, one + zero);
        }
        return ans;
    }
};