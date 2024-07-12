class Solution {
private:
    int r_ab(string &s) {
        int ans = 0;
        stack<char> st;
        for(auto &i : s) {
            if(i != 'b') st.push(i);
            else {
                if(!st.empty() and st.top() == 'a') {
                    st.pop();
                    ans++;
                }
                else st.push(i);
            }
        }
        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return ans;
    }
    int r_ba(string &s) {
        int ans = 0;
        stack<char> st;
        for(auto &i : s) {
            if(i != 'a') st.push(i);
            else {
                if(!st.empty() and st.top() == 'b') {
                    st.pop();
                    ans++;
                }
                else st.push(i);
            }
        }
        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
        int x_count = 0, y_count = 0;
        if(x < y) {
            y_count = r_ba(s);
            x_count = r_ab(s);
        }
        else {
            x_count = r_ab(s);
            y_count = r_ba(s);
        }
        return (x_count * x) + (y_count * y);
    }
};