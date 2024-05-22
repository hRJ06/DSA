class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        int n = s.length();
        function<void(int)> f = [&](int i) -> void {
            function<bool(int,int)> isPal = [&](int start, int end) -> bool {
                while(start < end) 
                    if(s[start++] != s[end--])
                        return false;
                return true;
            };
            if(i == n) {
                ans.push_back(cur);
                return;
            }
            for(int j = i; j < n; j++) {
                if(isPal(i, j)) {
                    cur.push_back(s.substr(i, j - i + 1));
                    f(j + 1);
                    cur.pop_back();
                }
            }
        };
        f(0); 
        return ans;
    }
};
