class Solution {
private:
    vector<string> f(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while(ss >> word) {
            words.push_back(word);
        }
        return words;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = f(sentence1), words2 = f(sentence2);
        int n = words1.size(), m = words2.size();
        unordered_set<string> prefix, suffix;
        if(n < m) {
            for(int i = 0; i<n; i++) {
                if(words1[i] != words2[i]) break;
                else prefix.insert(words1[i]);
            }
            for(int i = n - 1, j = m - 1; i>=0; i--, j--) {
                if(words1[i] != words2[j]) break;
                else suffix.insert(words1[i]);
            }
            for(auto &i : words1) 
                if(prefix.find(i) == prefix.end() and suffix.find(i) == suffix.end()) return false;
            return true;
        }
        else {
            for(int i = 0; i<m; i++) {
                if(words2[i] != words1[i]) break;
                else prefix.insert(words2[i]);
            }
            for(int i = m - 1, j = n - 1; i>=0; i--, j--) {
                if(words2[i] != words1[j]) break;
                else suffix.insert(words2[i]);
            }
            for(auto &i : words2) 
                if(prefix.find(i) == prefix.end() and suffix.find(i) == suffix.end()) return false;
            return true;
        }
        return true;
    }
};