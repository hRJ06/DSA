class Solution {
private:
    string vowelList = "aeiouAEIOU";
    string toLower(string word) {
        for(auto &i : word) {
            i = tolower(i);
        }
        return word;
    }
    string deVowel(string word) {
        string s = "";
        for(auto &i : word) {
            if(vowelList.find(i) != string::npos) s.push_back('*');
            else s.push_back(i);
        }
        return s;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> word(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lower;
        unordered_map<string, string> vowel;
        for(auto &i : wordlist) {
            string s = toLower(i);
            string t = deVowel(s);
            if(!lower.count(s)) lower[s] = i;
            if(!vowel.count(t)) vowel[t] = i;
        }
        vector<string> ans;
        for(auto &i : queries) {
            string store = "";
            if(word.find(i) != word.end()) {
                store = i;
            }
            else {
                string s = toLower(i);
                string t = deVowel(s);
                if(lower.count(s)) store = lower[s];
                else if(vowel.count(t)) store = vowel[t];
            }
            ans.push_back(store);
        }
        return ans;
    }
};