class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> S, T;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            char cS = s[i];
            char cT = t[i];
            if(S.find(cS) != S.end()) {
                if(S[cS] != cT)
                    return false;
            }
            else 
                if(T.find(cT) != T.end()) return false;
            S[cS] = cT;
            T[cT] = cS;
        }
        return true;
    }
};