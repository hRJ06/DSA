class Solution
{
    public:
    bool areIsomorphic(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        if(n != m) return 0;
        unordered_map<char,char> mp;
        for(int i = 0; i<n; i++) {
            if(mp.count(str1[i])) {
                if(mp[str1[i]] != str2[i]) return false;     
            }
            else {
                for(auto &j : mp) 
                    if(j.second == str2[i]) return false;
                mp[str1[i]] = str2[i];  
            }
        }
        return true;
    }
};