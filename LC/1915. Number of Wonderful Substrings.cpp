typedef long long ll;
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,ll> mp;
        mp[0] = 1;
        int cur_xor = 0;
        ll ans = 0;
        for(auto &c : word) {
            int shift = c - 'a';
            cur_xor ^= (1 << shift);
            ans += mp[cur_xor];
            for(char ch = 'a'; ch <= 'j'; ch++) {
                shift = ch - 'a';
                ll check_xor = (cur_xor ^ (1 << shift));
                ans += mp[check_xor];
            }
            mp[cur_xor]++;
        }
        return ans;
    }
};