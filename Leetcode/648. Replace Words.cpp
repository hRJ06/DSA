class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s(dictionary.begin(), dictionary.end());
        istringstream iss(sentence);
        vector<string> temp;
        string word, ans;
        while(iss >> word) temp.push_back(word);
        for(auto &i : temp) {
            int j = 0;
            while(j ++ <= i.length()) {
                string cur = i.substr(0, j);
                if(s.find(cur) != s.end()) {
                    ans += cur + " ";
                    break;
                }
                if(j == i.length()) ans += cur + " ";
            }
        }
        ans.erase(ans.size() - 1);
        return ans;
    }
};