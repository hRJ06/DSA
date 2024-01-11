class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<char> s;
        int n = S.length();
        for(int i = 0; i<n; i++) {
            char c = S[i];
            while(!s.empty() and s.top() > c and K > 0) {
                s.pop();
                K--;
            }
            if(!s.empty() or c != '0')
                s.push(c);
        }
        while(!s.empty() and K > 0) {
            s.pop();
            K--;
        }
        if(s.empty()) return "0";
        string ans = "";
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};