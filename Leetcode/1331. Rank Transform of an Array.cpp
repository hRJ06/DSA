class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v = arr;
        sort(v.begin(), v.end());
        int rank = 1;
        unordered_map<int,int> mp;
        int i = 0, j = 0, n = arr.size();
        while(j < n) {
            mp[v[i]] = rank++;
            while(j < n and v[i] == v[j]) j++;
            i = j;
        }
        for(auto &i : arr) i = mp[i];
        return arr;
    }
};