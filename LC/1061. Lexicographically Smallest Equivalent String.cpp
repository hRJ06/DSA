class Solution {
private:
    char f(char ch, unordered_map<char, vector<char>> &adj, vector<int> &v) {
        v[ch - 'a'] = 1;
        char ans = ch;
        for(auto &c : adj[ch]) {
            if(!v[c - 'a']) ans = min(ans, f(c, adj, v));
        }
        return ans;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int m = s1.length();
        unordered_map<char, vector<char>> adj;
        for(int i = 0; i<m; i++) {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans = "";
        for(auto &i : baseStr) {
            vector<int> v(26, 0);
            ans.push_back(f(i, adj, v));
        }
        return ans;
    }
};