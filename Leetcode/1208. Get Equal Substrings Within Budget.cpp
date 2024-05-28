class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0, cur = 0, i = 0;
        for(int j = 0; j<n; j++) {
            cur += abs(t[j] - s[j]);
            while(cur > maxCost) {
                cur -= abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans,j - i + 1);
        }
        return ans;
    }
};