class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i : nums) mp[i]++;
        int ans = -1;
        for(auto &i : nums) {
            if(i > 0 and mp.count(-1 * i)) ans = max(ans,i);
        }
        return ans;
    }
};