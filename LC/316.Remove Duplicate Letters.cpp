class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<bool> vis(26,false);
        vector<int> lastIndex(26,0);
        for(int i = 0; i<n; i++)
            lastIndex[s[i] - 'a'] = i;
        stack<int> st;
        for(int i = 0; i<n; i++) {
            int index = s[i] - 'a';
            if(vis[index]) continue;
            while(!st.empty() and st.top() > index and i < lastIndex[st.top()]) {
                vis[st.top()] = false;
                st.pop();
            }
            st.push(index);
            vis[index] = true;
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top() + 'a';
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};