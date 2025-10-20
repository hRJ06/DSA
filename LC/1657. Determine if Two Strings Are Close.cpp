class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26,0), f2(26,0);
        set<char> s1(word1.begin(),word1.end());
        set<char> s2(word2.begin(),word2.end());
        for(auto &i : word1) f1[i - 'a']++;
        for(auto &i : word2) f2[i - 'a']++;
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        return s1 == s2 and f1 == f2;
    }
};