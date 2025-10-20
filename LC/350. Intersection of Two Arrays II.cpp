class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int,int> mp;
        for(auto &i : nums1) mp[i]++;
        vector<int> ans;
        for(int i = 0; i<m; i++) {
            if(mp.contains(nums2[i]) and mp[nums2[i]]) {
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return ans;
    }
};