typedef long long ll;
class Solution {
private:
    vector<ll> dp;
    int MOD = 1e9 + 7;
    ll f(int length, int one, int zero, int low, int high) {   
        if(length > high) return 0;
        if(dp[length] != -1) return dp[length];
        ll ans = (length >= low and length <= high);
        ll a = f(length + zero, one, zero, low, high) % MOD;
        ll b = f(length + one, one, zero, low, high) % MOD;
        ans = (ans + (a + b) % MOD) % MOD;
        return dp[length] = ans; 
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high + 1, -1);
        return f(0, one, zero, low, high);
    }
};