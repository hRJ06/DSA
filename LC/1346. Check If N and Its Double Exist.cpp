class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        mp[arr[0]]++;
        int n = arr.size();
        for(int i = 1; i<n; i++) {
            int h = arr[i] / 2;
            if(mp.count(arr[i] * 2) or (mp.count(h) and (h * 2 == arr[i]))) return true;
            mp[arr[i]]++;
        }
        return false;
    }
};