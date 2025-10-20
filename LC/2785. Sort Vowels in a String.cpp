class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U';
    }
public:
    string sortVowels(string s) {
        vector<char> v;
        for(auto &i : s) {
            if(isVowel(i))
                v.push_back(i);
        }
        sort(v.begin(),v.end());
        int j = 0;
        for(auto &i : s)
            if(isVowel(i))
                i = v[j++];
        return s;
    }
};