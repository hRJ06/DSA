class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto &i : details) {
            string s = i.substr(11,2);
            int age = stoi(s);
            ans += (age > 60);
        }
        return ans;
    }
};
