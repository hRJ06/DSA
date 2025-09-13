class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u'});
        unordered_map<char, int> v, c;
        int a = 0, b = 0;
        for(auto &i : s) {
            if(vowel.find(i) != vowel.end()) {
                a = max(a, ++v[i]);
            }
            else {
                b = max(b, ++c[i]);
            }
        }
        return a + b;
    }
};