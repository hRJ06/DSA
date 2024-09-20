class Solution {
private:
    void f(vector<int> &lps, string store, int n) {
        /* n -> store_len */
        int i = 0, j = 1;
        while(j < n) {
            if(store[i] != store[j]) {
                if(!i) j++;
                else i = lps[i - 1];
            }
            else {
                i++;
                lps[j] = i;
                j++;
            }
        }
    }
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        string store = s + '#' + t;
        int n = store.length();
        vector<int> lps(n, 0);

        f(lps, store, n);

        /* Part not matched from index to n */
        string extra = s.substr(lps[n - 1]);
        
        reverse(extra.begin(), extra.end());
        return extra + s;
    }
};