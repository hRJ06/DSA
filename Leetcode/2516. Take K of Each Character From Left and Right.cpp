class Solution {
public:
    int takeCharacters(string s, int k) {
        /* 
            The probability of a character having at least K occurrences plus the probability of a character having at most K - 1 occurrences = 1.
        */
        if(!k) return 0;
        unordered_map<char,int> mp;
        for(auto &i : s) mp[i]++;
        for(auto &i : mp) if(i.second < k) return -1;
        if(mp.size() < 3) return -1;

        int i = 0, j = 0, n = s.length();

        int maxA = mp['a'] - k;
        int maxB = mp['b'] - k;
        int maxC = mp['c'] - k;

        unordered_map<char,int> cW;
        int ans = 0;
        while(j < n) {
            char ch = s[j];
            cW[ch]++;
            while((cW['a'] > maxA) or (cW['b'] > maxB) or (cW['c'] > maxC)) {
                cW[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return n - ans;
    }
};
