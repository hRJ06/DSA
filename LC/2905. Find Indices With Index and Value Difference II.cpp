class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        int mini = 0, maxi = 0, n = nums.size();
        for(int i = id; i<n; i++) {
            if(nums[i - id] < nums[mini]) mini = i - id;
            if(nums[i - id] > nums[maxi]) maxi = i - id;
            if(nums[i] - nums[mini] >= vd) return {mini,i};
            if(nums[maxi] - nums[i] >= vd) return {maxi,i};
        }
        return {-1,-1};
    }
};