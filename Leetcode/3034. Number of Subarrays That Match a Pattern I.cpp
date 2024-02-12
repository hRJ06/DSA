class Solution {
private:
    int f(int i,int j,vector<int> &nums,vector<int> &pattern) {
        if(j >= pattern.size()) return 1;
        if(i >= nums.size() - 1) return 0;
        bool a = !pattern[j] and nums[i] == nums[i + 1];
        bool b = pattern[j] == 1 and nums[i] < nums[i + 1];
        bool c = pattern[j] == -1 and nums[i] > nums[i + 1];
        if(a or b or c) {
            return f(i + 1,j + 1,nums,pattern);
        }
        return 0;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans += f(i,0,nums,pattern);
        }
        return ans;
    }
};