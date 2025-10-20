class Solution {
private:
    unordered_set<string> st;
    int ans = 0;
    void helper(string s, int index) {
        int n = s.length();
        if(index >= n) ans = max(ans, (int)st.size());
        string store = "";
        for(int i = index; i<n; i++) {
            store += s[i];
            if(st.find(store) != st.end()) continue;
            st.insert(store);
            helper(s, i + 1);
            st.erase(store);
        }
    }
public:
    int maxUniqueSplit(string s) {
        helper(s, 0);
        return ans;
    }
};