class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> s(begin(brokenLetters), end(brokenLetters));
        vector<string> store;
        int ans = 0;
        string cur = "";
        for(auto &i : text) {
            if(i != ' ') cur.push_back(i);
            else {
                store.push_back(cur);
                cur = "";
            }
        }
        store.push_back(cur);
        for(auto &i : store) {
            string str = i;
            bool check = true;
            for(auto &j : str) {
                if(s.count(j)) {
                    check = false;
                    break;
                }
            }
            if(check) ans++;
        }
        return ans;
    }
};