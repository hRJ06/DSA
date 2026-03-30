class Solution {
public:
    bool checkStrings(string s1, string s2) {
        /* 
            O - O -> E
            E - E -> E
        */
        unordered_map<char, int> odd, even;
        int n = s1.length();
        for(int i = 0; i<n; i++) {
            if(i & 1) odd[s1[i]]++;
            else even[s1[i]]++;
        }
        for(int i = 0; i<n; i++) {
            if(i & 1) odd[s2[i]]--;
            else even[s2[i]]--;
        }
        for(auto &i : odd) {
            if(i.second != 0) return false;
        }
        for(auto &i : even) {
            if(i.second != 0) return false;
        }
        return true;
    }
};