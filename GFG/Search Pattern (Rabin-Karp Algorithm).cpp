typedef long long ll;
class Solution
{
public:
    vector<int> search(string pattern, string text)
    {
        int n = text.length(), m = pattern.length(), d = 256, MOD = 101;
        ll h = 1;
        vector<int> ans;
        for(int i = 1; i<=m - 1; i++)
            h = (h * d) % MOD;
        ll p = 0, t = 0;
        for(int i = 0; i<m; i++) {
            p = (p * d + pattern[i]) % MOD;
            t = (t * d + text[i]) % MOD;
        }
        for(int i = 0; i<=n - m; i++) {
            if(p == t) {
                bool flag = true;
                for(int j = 0; j<m; j++) {
                    if(text[i + j] != pattern[j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans.push_back(i + 1);
            }
            if(i<n - m) {
                t = (d * (t - text[i] * h) + text[i + m]) % MOD;
                if(t < 0) t = t + MOD;
            }
        }
        return ans;
    }
};