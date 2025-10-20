class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> prefix(n);
        int count = 0; 
        for(int i = 0; i<n; i++) {
            string word = words[i];
            if(s.find(word[0]) != s.end() and s.find(word[word.length() - 1]) != s.end())
                count++;
            prefix[i] = count;
        }
        vector<int> ans;
        for(auto &i : queries) {
            int l = i[0], r = i[1];
            if(!l) ans.push_back(prefix[r]);
            else ans.push_back(prefix[r] - prefix[l - 1]);
        }
        return ans;
    }
};