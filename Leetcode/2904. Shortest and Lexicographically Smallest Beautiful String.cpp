class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int count = 0, i = 0, j = 0;
        while(j < n) {
            count += s[j] == '1';
            while(count == k) {
                string c = s.substr(i, j - i + 1);
                if(ans.empty() or (c.length() < ans.length() or (c.length() == ans.length() and c < ans))) 
                    ans = c;
                count -= s[i] == '1';
                i++;
            }
            j++;
        }
        return ans;
    }
};