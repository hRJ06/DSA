class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(m < n) return false;
        vector<int> f1(26, 0), f2(26, 0);
        for(auto &i : s1)
            f1[i - 'a']++;
        for(int i = 0; i<n; i++)
            f2[s2[i] - 'a']++;
        if(f1 == f2) return true;
        for(int i = 0, j = n; j<m; j++,i++) {
            f2[s2[i] - 'a']--;
            f2[s2[j] - 'a']++;
            if(f1 == f2) return true;
        }
        return false;
    }
};