class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        for(auto &i : s) {
            if(v.count(i)) return true;
        }
        return false;
    }
};