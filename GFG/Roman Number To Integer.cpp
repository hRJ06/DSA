class Solution {
  public:
    int romanToDecimal(string &str) {
        int n = str.length();
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans = mp[str[n - 1]];
        for(int i = n - 2; i>=0; i--) {
            int cur = mp[str[i]], next = mp[str[i + 1]];
            if(cur < next) ans -= cur;
            else ans += cur;
        }
        return ans;
    }
};