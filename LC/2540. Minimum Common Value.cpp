class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        int ans = INT_MAX;
        for(auto &i : nums2) {
            if(s.find(i) != s.end()) ans = min(ans,i);
        }
        return ans != INT_MAX ? ans : -1;
    }
};