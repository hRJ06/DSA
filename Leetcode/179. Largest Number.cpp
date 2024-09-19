class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> store;
        for(auto &i : nums) store.push_back(to_string(i));
        sort(store.begin(), store.end(), [&](string a, string b) {
            return a + b > b + a;
        });
        string ans = "";
        for(auto &i : store) ans += i;
        if(ans[0] == '0') return "0";
        return ans;
    }
};