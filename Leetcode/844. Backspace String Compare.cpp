class Solution {
private:
    string f(string &s) {
        stack<int> st;
        for(auto &i : s) i != '#' ? st.push(i) : (st.empty() ? void() : st.pop());  
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
public:
    bool backspaceCompare(string s, string t) {
        return f(s) == f(t);
    }
};
