typedef long long ll;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string ans = "";
        if((ll)numerator * (ll)denominator < 0) ans = "-";
        ll num = llabs((ll)numerator), den = llabs((ll)denominator);
        unordered_map<ll, int> mp;
        ll q = num / den, r = num % den;
        ans += to_string(q);
        if(!r) return ans;
        ans.push_back('.');
        while(r) {
            if(mp.count(r)) {
                ans.insert(mp[r], "(");
                ans.push_back(')');
                break;
            }
            mp[r] = ans.length();
            r *= 10;
            ll q_ = r / den, r_ = r % den;
            ans += to_string(q_);
            r = r_;
        }
        return ans;
    }
};