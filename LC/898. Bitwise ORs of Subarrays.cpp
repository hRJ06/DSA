class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, cur, ans;
        for(auto &i : arr) {
            for(auto &j : prev) {
                cur.insert(i | j);
                ans.insert(i | j);
            }
            cur.insert(i);
            prev = cur;
            cur.clear();
            ans.insert(i);
        }
        return ans.size();
    }
};