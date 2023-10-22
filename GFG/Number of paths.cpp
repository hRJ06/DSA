typedef long long ll;
class Solution
{   
    private:
    int MOD = 1e9 + 7;
    ll power(ll x,int y) {
        ll ans = 1;
        while(y) {
            if(y & 1)
                (ans *= x) %= MOD;
            y >>= 1;
            x = (x * x) % MOD;
        }
        return ans;
    }
    public:
    long long  numberOfPaths(int m, int n)
    {
        // Code Here
        ll ans = 1;
        for(int i = n; i<=(n + m - 2); i++) {
            (ans *= i) %= MOD;
            ll inv = power(i - n + 1,MOD - 2);
            (ans *= inv) %= MOD;
        }
        return ans;
    }
};