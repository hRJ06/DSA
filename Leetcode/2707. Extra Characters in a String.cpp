class Solution {
private:
    vector<int> dp;
    int f(int index, string &s, int n, unordered_set<string> &st) {
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        int ans = INT_MAX;
        string store = "";
        for(int i = index; i<n; i++) {
            store += s[i];
            int count = st.count(store) ? 0 : store.length();
            ans = min(ans,count + f(i + 1, s, n, st));
        }
        return dp[index] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        dp.resize(n, -1);
        unordered_set<string> st(begin(dictionary), end(dictionary));
        return f(0, s, n, st);
    }
};