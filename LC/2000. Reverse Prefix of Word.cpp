class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1, n = word.length();
        for(int i = 0; i<n; i++) {
            if(word[i] == ch) {
                index = i + 1;
                break;
            }
        }
        if(index == -1) index = 0;
        reverse(word.begin(), word.begin() + index);
        return word;
    }
};