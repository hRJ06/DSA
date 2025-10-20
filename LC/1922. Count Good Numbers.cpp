typedef long long ll;
class Solution {
private:
    int MOD = 1e9 + 7;
    ll find(ll x, ll y) {
        int ans = 1;
        while(y > 0) {
            if(y & 1) {
                ans = (ans * x) % MOD;
            }
            x = (x * x) % MOD;
            y >>= 1;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        return find(5, (n + 1) / 2) * find(4, n / 2) % MOD;
    }
};