class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++) {
            int r = arr[i] % k;
            if(r < 0) r += k;
            mp[r]++;
        }
        for(auto &i : mp) {
            int current = i.first;
            int need = k - current;
            if(!current) {
                if(mp[current] & 1) return false;
            }
            else if(!mp.count(need) or mp[current] != mp[need]) return false;
        }
        return true;
    }
};