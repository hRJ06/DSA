class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i : nums) mp[i]++;
        vector<int> store;
        for(auto &i : mp) store.push_back(i.first);
        sort(store.begin(), store.end(), [&](int a, int b) {
            return mp[a] != mp[b] ? mp[a] < mp[b] : a > b;
        });
        vector<int> ans;
        for(auto &i : store) {
            while(mp[i]--)
                ans.push_back(i);
        }
        return ans;
    }
};
