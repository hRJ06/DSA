class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0, n = s.length();
        for(int i = 1; i<n; i++) 
            ans += abs(s[i] - s[i - 1]);
        return ans;
    }
};