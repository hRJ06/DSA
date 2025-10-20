class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream stream(s1 + " " + s2);
        string word;
        unordered_map<string,int> mp;
        while(stream >> word) mp[word]++;
        vector<string> ans;
        for(auto &i : mp)
            if(i.second == 1) ans.push_back(i.first);
        return ans;
    }
};