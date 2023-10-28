class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD = 1e9 + 7;
        unordered_map<char,vector<char>> mp{{'s', {'a','e','i','o','u'}}, {'a',{'e'}}, {'e',{'a','i'}}, {'i',{'a','e','o','u'}}, {'o',{'i','u'}}, {'u',{'a'}}};
        unordered_map<char,vector<int>> dp;
        function <int(char,int)> f = [&](char ch,int r) -> int {
            if(!r) return 1;
            if(dp[ch][r] != -1) return dp[ch][r];
            int ans = 0;
            for(auto &i : mp[ch]) ans = (ans + f(i,r - 1) % MOD) % MOD;
            return dp[ch][r] = ans;
        };
        for(auto &i : mp) dp[i.first] = vector<int>(n + 1,-1);
        return f('s',n);
    }
};