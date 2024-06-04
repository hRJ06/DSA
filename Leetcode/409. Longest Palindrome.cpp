class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mp;
        for(auto &i : s) mp[i]++;
        int ans = 0;
        bool flag = false;
        for(auto &i : mp) {
            if(i.second & 1) {
                ans += i.second;
                if(!flag) flag = true;
                else ans -= 1;
            }
            else 
                ans += i.second;
        }
        return ans;
    }
};