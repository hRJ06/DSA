class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        vector<int> ans(n,0);
        long long r = 0;
        for(int i = 0; i<n; i++) {
            r = (r * 10 + word[i] - '0') % m;
            if(!r) ans[i] = 1;
        }
        return ans;
    }
};