class Solution {
private:
    bool f(string &s, string &t) {
        int m = s.length(), n = t.length();
        if(m != n) return false;
        int count = 0;
        for(int i = 0; i<m; i++) {
            if(s[i] != t[i]) count++;
        }
        return count != 1 ? false : true;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(), ans = 1, index = 0;
        vector<int> dp(n, 1), hash(n, - 1);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if((groups[j] != groups[i]) and f(words[i], words[j]) and (1 + dp[j] > dp[i])) {
                    hash[i] = j;
                    dp[i] = 1 + dp[j];
                    if(dp[i] > ans) {
                        ans = dp[i];
                        index = i;
                    }
                } 
            }
        }
        vector<string> result;
        while(index != -1) {
            result.push_back(words[index]);
            index = hash[index];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};