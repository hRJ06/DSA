class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        stack<char> st;
        for(auto &i : s) {
            if(!st.empty() and st.top() > i) {
                ans++;
                st.pop();
            }
            else
                st.push(i);
        }
        return ans;
    }
};