class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0, n = s.length();
        string store = "";
        for(int i = 0; i<n; i++) {
           store += to_string(s[i] - 'a' + 1);
        }
        while(k--) {
            int total = 0;
            for(int i = 0; i<store.length(); i++) {
                total += (store[i] - '0');
            }
            ans = total;
            store = to_string(total);
        }
        return ans;
    }
};