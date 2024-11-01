class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int index = 0;
        for(auto &i : s) {
            if(index < 2) {
                ans += i;
                index++;
            }
            else {
                if(ans[index - 1] == i and ans[index - 2] == i) continue;
                else {
                    ans += i;
                    index++;
                }
            }
        }
        return ans;
    }
};