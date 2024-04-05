class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        string ans = "";
        stack<char> st;
        for(int i = 0; i<n; i++) {
            if(st.empty() or abs(st.top() - s[i]) != 32) st.push(s[i]);
            else st.pop();
        }
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};