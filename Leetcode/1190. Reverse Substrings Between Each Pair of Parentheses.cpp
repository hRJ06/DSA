class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> v;
        int n = s.length();
        for(int i = 0; i<n; i++) {
            if(s[i] != ')') 
                v.push_back(s[i]);
            else {
                int index = v.size() - 1;
                while(v[index] != '(') {
                    index--;
                }
                v.erase(v.begin() + index);
                reverse(v.begin() + index, v.end());
            }
        }
        string ans = "";
        for(auto &i : v) ans += i;
        return ans;
    }
};