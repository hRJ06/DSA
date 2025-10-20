class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(), spaces.end());
        string ans = "";
        int n = s.size(), index = 0, m = spaces.size();
        for(int i = 0; i<n; i++) {
            if(index >= m or spaces[index] != i) ans += s[i];
            else {
                ans += ' ';
                ans += s[i];
                index++;
            }
        }
        return ans;
    }
};