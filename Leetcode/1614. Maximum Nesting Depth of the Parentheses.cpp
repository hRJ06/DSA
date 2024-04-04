class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cur = 0;
        for(auto &i : s) {
            if(i == ')') cur--;
            else if(i == '(') cur++;
            ans = max(ans,cur);
        }
        return ans;
    }
};