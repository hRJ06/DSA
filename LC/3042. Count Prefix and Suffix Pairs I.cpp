class Solution {
private:
    bool f(string s1, string s2) {
        if(s2.substr(0,s1.length()) != s1 or s2.substr(s2.length() - s1.length(),s1.length()) != s1) return false;
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                if(f(words[i],words[j])) ans++;
            }
        }
        return ans;
    }
};