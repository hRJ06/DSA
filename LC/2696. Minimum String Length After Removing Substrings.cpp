class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto &i : s) {
            if(st.empty()) st.push(i);
            else {
                if(i == 'B' and st.top() == 'A') st.pop();
                else if(i == 'D' and st.top() == 'C') st.pop();
                else st.push(i);
            }
        }
        return st.size();
    }
};