class Solution {
private:
    bool f(string s,string check) {
        int j = 0, n = s.length();
        for(int i = 0; i<n and j < 3; i++) 
            if(s[i] == check[j]) j++;
        return j == 3;
    }
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for(char a = 'a'; a<='z'; a++) {
            for(char b = 'a'; b<='z'; b++) {
                string store = string(1, a) + string(1,b) + string(1, a);
                ans += f(s,store);
            }
        }
        return ans;
    }
};