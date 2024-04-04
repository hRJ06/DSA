typedef long long ll;
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        ll n = s.size(), ans = 0, c = 1, x = 1, M = 1e9 + 7;
        for(int i = n - 1; i>=0; i--)
            ans = (ans + (i + 1) * c % M * (s[i]-'0') % M) % M, x = (x * 10) % M, c = (c + x) % M;
        return ans;
    }
};