typedef long long ll;
class Solution{
public:
    long long sequence(int n){
        // code here
        ll ans = 0, k = 1;
        int MOD = 1e9 + 7;
        for(int i = 1; i<=n; i++) {
            ll res = 1;
            for(int j = 0; j<i; j++) {
                res = (res * k++) % MOD;
            }
            ans = (ans + res) % MOD;
        }
        return ans;
    }
};