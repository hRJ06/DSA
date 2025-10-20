class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 1; i<n; i++) {
            string store = "";
            for(auto &j : s)
                store += j == '0' ? '1' : '0';
            reverse(begin(store), end(store));
            string to_add = "1";
            to_add += store;
            s += to_add;
        }
        return s[k - 1];
    }
};