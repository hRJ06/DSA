class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";
        while(n--) {
            ans += (n % 26) + 'A';
            n /= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};