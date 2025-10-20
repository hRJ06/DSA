class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        for(auto &i : chars) mp[i]++;
        int ans = 0;
        for(auto &i : words) {
            unordered_map<char,int> track;
            bool f = true;
            for(auto &j : i) {
                if(++track[j] > mp[j]) {
                    f = false;
                    break;       
                }
            }
            if(f) ans += i.length();
            f = true;
        }
        return ans;
    }
};