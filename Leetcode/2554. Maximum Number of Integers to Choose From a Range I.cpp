class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s(begin(banned), end(banned));
        int ans = 0, cur = 0;
        for(int i = 1; i<=n; i++) {
            if(s.find(i) != s.end()) continue;
            if(cur + i > maxSum) break;
            ans++;
            cur += i;
        }
        return ans;
    }
};