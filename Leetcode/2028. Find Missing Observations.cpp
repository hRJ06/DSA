class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = accumulate(rolls.begin(), rolls.end(), 0);
        int left = (mean * (n + m)) - total;
        int each = left / n, extra = left % n;
        /* Handle for extra */
        if(extra < 0) return {};
        vector<int> ans(n, each);
        int i = 0;
        while(extra) {
            ans[i++]++;
            extra--;
        }
        /* Handle for left */
        for(auto &i : ans) 
            if(i <= 0 or i > 6) return {};
        return ans;
    }
};