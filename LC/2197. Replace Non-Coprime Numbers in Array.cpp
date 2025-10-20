class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        for(auto &i : nums) {
            while(!s.empty()) {
                int top = s.top();
                int gcd = __gcd(top, i);
                if(gcd > 1) {
                    s.pop();
                    i = lcm(top, i);
                }
                else break;
            }
            s.push(i);
        }
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};