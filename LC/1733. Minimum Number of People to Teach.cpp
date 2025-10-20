class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sad;
        for(auto &i : friendships) {
            int u = i[0] - 1;
            int v = i[1] - 1;
            unordered_set<int> uLang(begin(languages[u]), end(languages[u]));
            bool check = false;
            for(auto &j : languages[v]) {
                if(uLang.find(j) != uLang.end()) {
                    check = true;
                    break;
                }
            }
            if(!check) {
                sad.insert(u);
                sad.insert(v);
            }
        }
        vector<int> langCount(n + 1, 0);
        int most = 0;
        for(auto &i : sad) {
            for(auto &l : languages[i]) {
                most = max(most, ++langCount[l]);
            }
        }
        return sad.size() - most;
    }
};