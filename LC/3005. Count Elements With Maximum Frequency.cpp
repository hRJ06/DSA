class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int max_freq = 0;
        for(auto &i : nums) {
            mp[i]++;
            max_freq = max(max_freq,mp[i]);
        }
        int ans = 0;
        for(auto &i : nums) {
            if(mp[i] == max_freq) ans++;
        }
        return ans;
    }
};