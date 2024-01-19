class Solution {
public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<int> top(K + 1, 0);
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i<N; i++) {
            mp[arr[i]]++;
            top[K] = arr[i];
            auto f = find(top.begin(), top.end() - 1, arr[i]);
            int index = distance(top.begin(), f) - 1;
            for(int j = index; j>=0; j--) {
                if(mp[top[j]] < mp[top[j + 1]] or (mp[top[j]] == mp[top[j + 1]] and top[j] > top[j + 1])) 
                    swap(top[j], top[j + 1]);
                else 
                    break;
            }
            vector<int> store;
            for(int i = 0; i<K and top[i] != 0; i++) {
                store.push_back(top[i]);
            }
            ans.push_back(store);
        }
        return ans;
    }
};