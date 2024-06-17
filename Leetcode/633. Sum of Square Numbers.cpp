class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        unordered_map<int,int> mp;
        for(int i = 0; i<=n; i++) mp[i * i] = 1;
        for(int i = 0; i<=n; i++)
            if(mp.find(c - i * i) != mp.end()) return true;
        return false;
    }
};