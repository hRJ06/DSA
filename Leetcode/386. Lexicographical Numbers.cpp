class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> store;
        for(int i = 1; i<=n; i++) store.push_back(to_string(i));
        sort(begin(store), end(store));
        vector<int> ans;
        for(auto &i : store) ans.push_back(stoi(i));
        return ans;
    }
};