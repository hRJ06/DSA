class Solution {
private:
    bool pal(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) 
            if(s[i++] != s[j--]) return false;
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &i : words) 
            if(pal(i)) return i;
        return "";
    }
};