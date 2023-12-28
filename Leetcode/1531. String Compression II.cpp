int dp[101][27][101][101];
class Solution {
private:
    unordered_set<int> possibleLen = {1,9,99};
    int solve(string &s,int i,char lastChar,int lastCharCount,int k) {
        if(k < 0) return 1e8;
        if(i >= s.length()) return 0;
        if(dp[i][lastChar - 'a'][lastCharCount][k] != -1) return dp[i][lastChar - 'a'][lastCharCount][k];
        int delChar = solve(s,i + 1,lastChar,lastCharCount,k - 1);
        int keepChar;
        if(s[i] != lastChar) {
            keepChar = solve(s,i + 1,s[i],1,k) + 1;
        }
        else {
            keepChar = solve(s,i + 1,lastChar,lastCharCount + 1,k) + (possibleLen.count(lastCharCount) ? 1 : 0);   
        }
        return dp[i][lastChar - 'a'][lastCharCount][k] = min(keepChar,delChar);
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,'z' + 1,0,k);
    }
};