class Solution {
private:
    vector<vector<int>> ans;
    void f(vector<int> &v, int index, int k, vector<int> &store) {
        if(!k) {
            ans.push_back(store);
            return;
        }
        for(int i = index; i<v.size(); i++) {
            if(i > index and v[i] == v[i - 1]) continue;
            if(v[i] <= k) {
                store.push_back(v[i]);
                f(v, i + 1, k - v[i], store);
                store.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> store;
        sort(candidates.begin(), candidates.end());
        f(candidates, 0, target, store);
        return ans;
    }
};