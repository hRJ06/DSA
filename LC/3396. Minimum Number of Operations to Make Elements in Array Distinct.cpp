class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int ans = 0, n = nums.size();
            unordered_map<int, int> mp;
            for(int i = n - 1; i>=0; i--) {
                if(mp.count(nums[i])) return ceil((i + 1) / 3.0);
                mp[nums[i]]++;
            }
            return 0;
        }
    };