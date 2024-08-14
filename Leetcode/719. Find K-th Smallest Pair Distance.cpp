class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int ele = *max_element(nums.begin(), nums.end());
        vector<int> d(ele + 1, 0);
        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                int diff = abs(nums[i] - nums[j]);
                d[diff]++;
            }
        }
        for(int i = 0; i<ele + 1; i++) {
            k -= d[i];
            if(k <= 0) 
                return i;
        }
        return -1;
    }
};