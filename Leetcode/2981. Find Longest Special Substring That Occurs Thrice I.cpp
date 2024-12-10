class Solution {
private:
    bool f(int k, int n, string s) {
        unordered_map<char, int> charMp;
        unordered_map<char, int> strMp;
        for(int i = 0; i<k; i++) {
            charMp[s[i]]++;
        }
        if(charMp.size() <= 1) {
            strMp[s[0]]++;
        }
        for(int i = 0, j = k; j<n; i++, j++) {
            if(!(--charMp[s[i]])) charMp.erase(s[i]);
            charMp[s[j]]++;
            if(charMp.size() <= 1) {
                strMp[s[j]]++;
                if(strMp[s[j]] >= 3) return true;
            }
        }
        return false;
    }
public:
    int maximumLength(string s) {
        int n = s.length();
        int start = 1, end = n, ans = -1;
        while(start <= end) {
            int m = start + (end - start) / 2;
            if(f(m, n, s)) {
                ans = m;  
                start = m + 1;
            } 
            else {
                end = m - 1;  
            }
        }
        return ans;
    }
};
