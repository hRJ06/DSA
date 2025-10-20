class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;
        for(auto &i : num) {
            while(!s.empty() and s.top() > i and k) {
                s.pop();
                k--;
            }
            s.push(i);
        }
        while(k > 0) {
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        int index = 0;
        for(int i = ans.size() - 1; i>=0; i--) {
            if(ans[i] != '0') {
                index = i;
                break;
            }
        }
        ans = ans.substr(0,index + 1);
        reverse(ans.begin(),ans.end());
        return ans != "" ? ans : "0";
    }
};