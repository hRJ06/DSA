class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> dp(n, 1), hash(n,-1);
        int index = 0;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(groups[j] != groups[i] and dp[j] + 1 > dp[i]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                    index = i;
                } 
            }
        }
        vector<string> ans;
        while(index != -1) {
            ans.push_back(words[index]);
            index = hash[index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};