class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> v(26,0);
        for(auto &i : words) {
            for(auto &j : i) {
                v[j - 'a']++;
            }
        }
        int n = words.size();
        for(int i = 0; i<26; i++) {
            if(v[i] % n) return false;
        }
        return true;
    }
};