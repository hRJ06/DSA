class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string s = "";
        map<int, string> mp;
        int index = 1;
        for(auto &i : sentence) {
            if(i != ' ') s += i;
            else {
                mp[index++] = s;
                s = "";
            }
        }
        mp[index] = s;
        for(auto &i : mp) {
            string word = i.second;
            string cur = "";
            for(auto &j : word) {
                cur += j;
                if(cur == searchWord) return i.first;
            }
        }
        return -1;
    }
};