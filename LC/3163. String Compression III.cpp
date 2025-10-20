class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int j = 0, n = word.length();
        while(j < n) {
            char ch = word[j];
            int i = j + 1, count = 1;
            while(i < n and word[i] == word[j] and count < 9) {
                i++;
                count++;
            }
            ans += (count + '0');
            ans += ch;
            j = i;
        }
        return ans;
    }
};