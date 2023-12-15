
typedef long long ll;
class Solution {
public:
    ll countWays(int n, int k) {
        if(n == 1) return k;
        int mod = 1e9 + 7;
        ll withoutSame = k;
        ll withSame = 0;
        for(int i = n - 2; i>=0; i--) {
            ll prevWithoutSame = withoutSame;
            withoutSame = (((k - 1) * (withoutSame + withSame)) % mod);
            withSame = prevWithoutSame;
        }
        return (withoutSame + withSame) % mod;
    }
};